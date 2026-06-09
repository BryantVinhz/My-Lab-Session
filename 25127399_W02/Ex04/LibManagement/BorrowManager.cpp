#include "BorrowManager.h"

BorrowManager::BorrowManager(Library& library)
    : library_(library) {
}

int BorrowManager::daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

bool BorrowManager::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int BorrowManager::daysBetween(const Date& from, const Date& to) {
    auto dayCount = [&](const Date& date) {
        int days = date.year() * 365 + date.day();
        for (int month = 1; month < date.month(); ++month) {
            days += daysInMonth(month, date.year());
        }
        for (int year = 0; year < date.year(); ++year) {
            days += isLeapYear(year) ? 1 : 0;
        }
        return days;
    };
    return dayCount(to) - dayCount(from);
}

Date BorrowManager::calculateDueDate(const Date& borrowDate) const {
    int day = borrowDate.day();
    int month = borrowDate.month();
    int year = borrowDate.year();

    day += 7;
    int maxDay = daysInMonth(month, year);
    if (day > maxDay) {
        day -= maxDay;
        month += 1;
        if (month > 12) {
            month = 1;
            year += 1;
        }
    }

    return Date(day, month, year);
}

long BorrowManager::calculateLateFee(const Date& dueDate, const Date& actualDate) const {
    int overdueDays = daysBetween(dueDate, actualDate);
    if (overdueDays <= 0) {
        return 0;
    }
    return overdueDays * 5000L;
}

long BorrowManager::calculateLossFee(const Book& book) const {
    return book.getPrice() * 2;
}

bool BorrowManager::borrowBook(const std::string& readerCode, size_t bookIndex, const Date& today) {
    Reader* reader = library_.findReaderByCode(readerCode);
    if (!reader) {
        return false;
    }

    auto& books = library_.getBooks();
    if (bookIndex >= books.size()) {
        return false;
    }

    Book& book = books[bookIndex];
    if (book.getQuantity() <= 0 || !reader->canBorrow()) {
        return false;
    }

    Date dueDate = calculateDueDate(today);
    reader->borrowBook(book, today, dueDate);
    book.decrementQuantity();
    library_.saveBooks();
    return true;
}

bool BorrowManager::returnBook(const std::string& readerCode, size_t borrowIndex, const Date& today, long& fee) {
    Reader* reader = library_.findReaderByCode(readerCode);
    if (!reader || borrowIndex >= static_cast<size_t>(reader->borrowedCount())) {
        fee = 0;
        return false;
    }

    const BorrowRecord record = reader->getBorrowedBooks()[borrowIndex];
    Book* book = library_.findBookByISBN(record.book.getISBN());
    if (book) {
        book->incrementQuantity();
        library_.saveBooks();
    }

    fee = calculateLateFee(record.dueDate, today);
    reader->returnBook(borrowIndex);
    return true;
}

bool BorrowManager::loseBook(const std::string& readerCode, size_t borrowIndex, long& fee) {
    Reader* reader = library_.findReaderByCode(readerCode);
    if (!reader || borrowIndex >= static_cast<size_t>(reader->borrowedCount())) {
        fee = 0;
        return false;
    }

    const BorrowRecord record = reader->getBorrowedBooks()[borrowIndex];
    fee = calculateLossFee(record.book);
    reader->returnBook(borrowIndex);
    return true;
}
