#include "statistics.h"

#include <iostream>
#include <map>

Statistics::Statistics(const Library& library)
    : library_(library) {
}

void Statistics::printTotalBooks() const {
    int totalBooks = 0;
    for (const Book& book : library_.getBooks()) {
        totalBooks += book.getQuantity();
    }
    std::cout << "STATISTICS OF NUMBER OF BOOKS IN LIBRARY\n";
    std::cout << "NUMBER OF BOOKS IN LIBRARY NOW: " << totalBooks << "\n";
}

void Statistics::printBooksByType() const {
    std::map<std::string, int> counts;
    for (const Book& book : library_.getBooks()) {
        counts[book.getType()] += book.getQuantity();
    }

    std::cout << "STATISTICS FOR NUMBER OF BOOKS (CATEGORIES)\n";
    for (const auto& pair : counts) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

void Statistics::printTotalReaders() const {
    std::cout << "STATISTICS OF NUMBER OF READERS IN LIBRARY\n";
    std::cout << "NUMBER OF READERS IN LIBRARY NOW: " << library_.readerCount() << "\n";
}

void Statistics::printGenderDistribution() const {
    int maleCount = 0;
    int femaleCount = 0;
    for (const Reader& reader : library_.getReaders()) {
        if (reader.getGender() == "MALE") {
            ++maleCount;
        } else {
            ++femaleCount;
        }
    }
    std::cout << "NUMBERS OF MALES IN LIBRARY: " << maleCount << "\n";
    std::cout << "NUMBERS OF FEMALES IN LIBRARY: " << femaleCount << "\n";
}

void Statistics::printBooksBorrowed() const {
    int count = 0;
    for (const Reader& reader : library_.getReaders()) {
        count += reader.borrowedCount();
    }
    std::cout << "The NUMBER OF BOOKS WHICH ARE BEING BORROWED: " << count << "\n";
}

void Statistics::printLateReaders(const Date& today) const {
    int count = 0;
    for (const Reader& reader : library_.getReaders()) {
        for (const BorrowRecord& record : reader.getBorrowedBooks()) {
            if (record.dueDate < today && !(record.dueDate == today)) {
                ++count;
            }
        }
    }
    std::cout << "THE NUMBER OF READERS WHO ARE MISSING DEADLINE: " << count << "\n";
}
