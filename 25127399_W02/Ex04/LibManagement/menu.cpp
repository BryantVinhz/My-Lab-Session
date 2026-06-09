#include "menu.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

namespace {

std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(static_cast<unsigned char>(str[start]))) {
        ++start;
    }
    size_t end = str.size();
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1]))) {
        --end;
    }
    return str.substr(start, end - start);
}

std::string toUpper(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return value;
}

bool isDigits(const std::string& value) {
    return !value.empty() && std::all_of(value.begin(), value.end(), ::isdigit);
}

bool isAlphaSpace(const std::string& value) {
    return !value.empty() && std::all_of(value.begin(), value.end(), [](unsigned char c) {
        return std::isalpha(c) || std::isspace(c);
    });
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
        default:
            return 31;
    }
}

Date inputDate(const std::string& label) {
    std::cout << label << "\n";
    int year = 0;
    while (year < 2000) {
        std::cout << "YEAR: ";
        std::string line;
        std::getline(std::cin, line);
        try {
            year = std::stoi(line);
        } catch (...) {
            year = 0;
        }
        if (year < 2000) {
            std::cout << "FILL AGAIN: \n";
        }
    }

    int month = 0;
    while (month < 1 || month > 12) {
        std::cout << "MONTH: ";
        std::string line;
        std::getline(std::cin, line);
        try {
            month = std::stoi(line);
        } catch (...) {
            month = 0;
        }
        if (month < 1 || month > 12) {
            std::cout << "FILL AGAIN: \n";
        }
    }

    int day = 0;
    int maxDay = daysInMonth(month, year);
    while (day < 1 || day > maxDay) {
        std::cout << "DAY: ";
        std::string line;
        std::getline(std::cin, line);
        try {
            day = std::stoi(line);
        } catch (...) {
            day = 0;
        }
        if (day < 1 || day > maxDay) {
            std::cout << "FILL AGAIN: \n";
        }
    }

    return Date(day, month, year);
}

} // namespace

MenuController::MenuController()
    : library_(), borrowManager_(library_), statistics_(library_) {
    library_.load();
}

std::string MenuController::readLine() const {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

int MenuController::readIntInRange(int minValue, int maxValue) const {
    while (true) {
        std::string line = readLine();
        try {
            int value = std::stoi(line);
            if (value >= minValue && value <= maxValue) {
                return value;
            }
        } catch (...) {
        }
        std::cout << "PLEASE FILL AGAIN: ";
    }
}

std::string MenuController::readNonEmptyLine(const std::string& prompt) const {
    while (true) {
        std::cout << prompt;
        std::string line = trim(readLine());
        if (!line.empty()) {
            return line;
        }
        std::cout << "PLEASE FILL AGAIN.\n";
    }
}

void MenuController::pauseExecution() const {
    system("pause");
}

void MenuController::clearScreen() const {
    system("cls");
}

void MenuController::showMainMenu() const {
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||              LIBRARY MANAGEMENT           ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             1. Readers management         ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             2. Books management           ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             3. Borrow book                ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             4. Return book                ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             5. Statistics                 ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||             6. Exit                       ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                   \n Which function do you want to choose (1,2,3...): ";
}

void MenuController::showReaderMenu() const {
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||              READERS MANAGEMENT           ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        a. List of readers in library      ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        b. Add reader                      ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        c. Adjust information              ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        d. Delete reader                   ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        e. Find reader by ID number        ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        f. Find book by name of reader     ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        g. Exit                            ||\n";
    std::cout << "                                ===============================================\n";
}

void MenuController::showBookMenu() const {
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||              BOOKS MANAGEMENT             ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        a. List of books in library        ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        b. Add book                        ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        c. Adjust information              ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        d. Delete book                     ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        e. Find book by ISBN               ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        f. Find book by name of book       ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||        g. Exit                            ||\n";
    std::cout << "                                ===============================================\n";
}

void MenuController::showStatisticsMenu() const {
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||                 STATISTICS                ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     a. NUMBER OF BOOKS IN LIBRARY         ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     b. NUMBER OF BOOKS (CATEGORIES)       ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     c. NUMBER OF READERS                  ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     d. NUMBER OF READERS (GENDER)         ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     e. NUMBER OF BOOKS BORROWED           ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     f. NUMBER OF READERS WHO ARE MISS DL  ||\n";
    std::cout << "                                ===============================================\n";
    std::cout << "                                ||     g. Exit                               ||\n";
    std::cout << "                                ===============================================\n";
}

Date MenuController::inputCurrentDate() const {
    std::cout << "PLEASE FILL THE DATE BEFORE USING APP!\n";
    return inputDate("FILL TODAY'S DATE");
}

void MenuController::run() {
    bool running = true;
    while (running) {
        std::cout << "WAITING SCREEN!!!\n";
        std::cout << "1. USE APP\n";
        std::cout << "2. CLOSE APP\n";
        std::cout << "\n YOUR CHOICE: ";
        int choice = readIntInRange(1, 2);
        if (choice == 2) {
            running = false;
            continue;
        }

        clearScreen();
        Date today = inputCurrentDate();
        clearScreen();

        bool sessionActive = true;
        while (sessionActive) {
            showMainMenu();
            char choice = 0;
            std::string line = readLine();
            if (!line.empty()) {
                choice = line[0];
            }
            while (choice < '1' || choice > '6') {
                std::cout << "                                   \n ERROR. PLEASE FILL AGAIN: ";
                line = readLine();
                if (!line.empty()) {
                    choice = line[0];
                }
            }

            clearScreen();
            switch (choice) {
                case '1':
                    runReaderMenu();
                    break;
                case '2':
                    runBookMenu();
                    break;
                case '3':
                    borrowBook(today);
                    clearScreen();
                    break;
                case '4':
                    returnBook(today);
                    clearScreen();
                    break;
                case '5':
                    runStatisticsMenu();
                    break;
                case '6':
                    sessionActive = false;
                    break;
            }
        }
    }
}

void MenuController::runReaderMenu() {
    bool active = true;
    while (active) {
        showReaderMenu();
        std::cout << "                                   \n Which function do you want to choose (a,b,c...): ";
        std::string line = readLine();
        char choice = line.empty() ? '\0' : line[0];
        while (choice < 'a' || choice > 'g') {
            std::cout << "                                   \n ERROR. PLEASE FILL AGAIN: ";
            line = readLine();
            choice = line.empty() ? '\0' : line[0];
        }

        clearScreen();
        switch (choice) {
            case 'a':
                printReaders();
                break;
            case 'b':
                addReader();
                break;
            case 'c':
                adjustReader();
                break;
            case 'd':
                deleteReader();
                break;
            case 'e':
                findReaderByIdNumber();
                break;
            case 'f':
                findBooksByReader();
                break;
            case 'g':
                active = false;
                break;
        }
        clearScreen();
    }
}

void MenuController::runBookMenu() {
    bool active = true;
    while (active) {
        showBookMenu();
        std::cout << "                                 \n Which function do you want to choose (a,b,c...): ";
        std::string line = readLine();
        char choice = line.empty() ? '\0' : line[0];
        while (choice < 'a' || choice > 'g') {
            std::cout << "                                   \n ERROR. PLEASE FILL AGAIN: ";
            line = readLine();
            choice = line.empty() ? '\0' : line[0];
        }

        clearScreen();
        switch (choice) {
            case 'a':
                printBooks();
                break;
            case 'b':
                addBook();
                break;
            case 'c':
                adjustBook();
                break;
            case 'd':
                deleteBook();
                break;
            case 'e':
                findBookByISBN();
                break;
            case 'f':
                findBookByTitle();
                break;
            case 'g':
                active = false;
                break;
        }
        clearScreen();
    }
}

void MenuController::runStatisticsMenu() const {
    bool active = true;
    while (active) {
        showStatisticsMenu();
        std::cout << "                                 \n Which function do you want to choose (a,b,c...): ";
        std::string line = readLine();
        char choice = line.empty() ? '\0' : line[0];
        while (choice < 'a' || choice > 'g') {
            std::cout << "                                   \n ERROR. PLEASE FILL AGAIN: ";
            line = readLine();
            choice = line.empty() ? '\0' : line[0];
        }

        clearScreen();
        switch (choice) {
            case 'a':
                statistics_.printTotalBooks();
                pauseExecution();
                break;
            case 'b':
                statistics_.printBooksByType();
                pauseExecution();
                break;
            case 'c':
                statistics_.printTotalReaders();
                pauseExecution();
                break;
            case 'd':
                statistics_.printGenderDistribution();
                pauseExecution();
                break;
            case 'e':
                statistics_.printBooksBorrowed();
                pauseExecution();
                break;
            case 'f':
                statistics_.printLateReaders(inputCurrentDate());
                pauseExecution();
                break;
            case 'g':
                active = false;
                break;
        }
        clearScreen();
    }
}

void MenuController::printReaders() const {
    const auto& readers = library_.getReaders();
    std::cout << "LIST OF READERS IN LIBRARY\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(10) << "CODE";
    std::cout << "  ||  " << std::setw(22) << "FULL NAME";
    std::cout << "  ||  " << std::setw(15) << "ID NUMBER";
    std::cout << "  ||   " << std::setw(8) << "DATEOFBIRTH";
    std::cout << "  ||  " << std::setw(3) << "GENDER";
    std::cout << "  ||  " << std::setw(30) << "EMAIL";
    std::cout << "  ||  " << std::setw(40) << "ADDRESS";
    std::cout << "  ||   " << std::setw(3) << "CREATING";
    std::cout << "  ||   " << std::setw(3) << "EXPIRING";
    std::cout << "  ||\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const Reader& reader : readers) {
        std::cout << "|| " << std::left << std::setw(10) << reader.getCode();
        std::cout << "  ||  " << std::setw(22) << reader.getName();
        std::cout << "  ||  " << std::setw(15) << reader.getIdNumber();
        std::cout << "  ||   " << std::setw(8) << reader.getDob().toString('-');
        std::cout << "  ||  " << std::setw(7) << reader.getGender();
        std::cout << "  ||  " << std::setw(30) << reader.getEmail();
        std::cout << "  ||  " << std::setw(40) << reader.getAddress();
        std::cout << "  ||   " << std::setw(10) << reader.getCreateDate().toString('-');
        std::cout << "  ||   " << std::setw(10) << reader.getExpireDate().toString('-');
        std::cout << "  ||\n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    pauseExecution();
}

void MenuController::printBooks() const {
    const auto& books = library_.getBooks();
    std::cout << "LIST OF BOOKS IN LIBRARY\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(12) << "ISBN";
    std::cout << "  || " << std::setw(20) << "NAME";
    std::cout << "  || " << std::setw(20) << "AUTHOR";
    std::cout << "  || " << std::setw(20) << "PUBLISHER";
    std::cout << "  || " << std::setw(5) << "YEAR";
    std::cout << "  || " << std::setw(15) << "TYPE";
    std::cout << "  || " << std::setw(10) << "PRICE";
    std::cout << "  || " << std::setw(10) << "QUANTITY";
    std::cout << "  ||\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const Book& book : books) {
        std::cout << "|| " << std::left << std::setw(12) << book.getISBN();
        std::cout << "  || " << std::setw(20) << book.getTitle();
        std::cout << "  || " << std::setw(20) << book.getAuthor();
        std::cout << "  || " << std::setw(20) << book.getPublisher();
        std::cout << "  || " << std::setw(5) << book.getPublishingYear();
        std::cout << "  || " << std::setw(15) << book.getType();
        std::cout << "  || " << std::setw(10) << book.getPrice();
        std::cout << "  || " << std::setw(10) << book.getQuantity();
        std::cout << "  ||\n";
        std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
    pauseExecution();
}

void MenuController::addReader() {
    std::string code;
    do {
        code = readNonEmptyLine("CODE OF READER (YOUR ID STUDENT NUMBER): ");
    } while (!isDigits(code) || code.size() != 8);

    std::string name;
    do {
        name = readNonEmptyLine("NAME OF READER: ");
    } while (!isAlphaSpace(name));
    name = toUpper(name);

    std::string idNumber;
    do {
        idNumber = readNonEmptyLine("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
    } while (!isDigits(idNumber) || idNumber.size() != 12);

    Date dob = inputDate("FILL YOUR BIRTHDAY");

    int genderChoice = 0;
    std::cout << "PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ";
    genderChoice = readIntInRange(0, 1);
    std::string gender = (genderChoice == 1) ? "MALE" : "FEMALE";

    std::string email;
    do {
        email = readNonEmptyLine("EMAIL OF READER: ");
    } while (email.size() > 50);

    std::string address;
    do {
        address = readNonEmptyLine("ADDRESS OF READER (ADDRESS NUMBER, WARD, DISTRICT): ");
    } while (address.size() > 50);

    Date createDate = inputDate("FILL YOUR CARD CREATING DAY");
    Date expireDate = createDate.addYears(4);

    Reader reader(code, name, idNumber, dob, gender, email, address, createDate, expireDate);
    library_.addReader(reader);
    library_.saveReaders();
}

void MenuController::adjustReader() {
    const auto& readers = library_.getReaders();
    if (readers.empty()) {
        std::cout << "No readers available." << std::endl;
        pauseExecution();
        return;
    }
    printReaders();
    std::cout << "PLEASE CHOOSE A READER TO ADJUST INFORMATION (1,2,..," << readers.size() << "): ";
    int index = readIntInRange(1, static_cast<int>(readers.size())) - 1;

    Reader updated = library_.getReaders()[index];
    std::cout << "WHICH INFORMATION DO YOU NEED TO ADJUST?\n";
    std::cout << "1. CODE OF READER\n";
    std::cout << "2. NAME OF READER\n";
    std::cout << "3. CITIZEN ID NUMBER\n";
    std::cout << "4. DATE OF BIRTH\n";
    std::cout << "5. GENDER\n";
    std::cout << "6. EMAIL\n";
    std::cout << "7. ADDRESS\n";
    std::cout << "8. CARD CREATING DATE\n";
    int field = readIntInRange(1, 8);

    switch (field) {
        case 1: {
            std::string code;
            do {
                code = readNonEmptyLine("CODE OF READER (YOUR ID STUDENT NUMBER): ");
            } while (!isDigits(code) || code.size() != 8);
            updated.setCode(code);
            break;
        }
        case 2: {
            std::string name;
            do {
                name = readNonEmptyLine("NAME OF READER: ");
            } while (!isAlphaSpace(name));
            updated.setName(toUpper(name));
            break;
        }
        case 3: {
            std::string idNumber;
            do {
                idNumber = readNonEmptyLine("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER): ");
            } while (!isDigits(idNumber) || idNumber.size() != 12);
            updated.setIdNumber(idNumber);
            break;
        }
        case 4:
            updated.setDob(inputDate("FILL DATE OF BIRTH"));
            break;
        case 5: {
            std::cout << "PLEASE FILL 1 ( MALE) OR FILL 0( FEMALE): ";
            int choice = readIntInRange(0, 1);
            updated.setGender(choice == 1 ? "MALE" : "FEMALE");
            break;
        }
        case 6: {
            std::string email;
            do {
                email = readNonEmptyLine("EMAIL OF READER: ");
            } while (email.size() > 50);
            updated.setEmail(email);
            break;
        }
        case 7: {
            std::string address;
            do {
                address = readNonEmptyLine("ADDRESS OF READER (ADDRESS NUMBER, WARD, DISTRICT): ");
            } while (address.size() > 50);
            updated.setAddress(address);
            break;
        }
        case 8: {
            Date createDate = inputDate("FILL CARD CREATING DATE");
            updated.setCreateDate(createDate);
            updated.setExpireDate(createDate.addYears(4));
            break;
        }
    }

    library_.updateReader(index, updated);
    library_.saveReaders();
}

void MenuController::deleteReader() {
    const auto& readers = library_.getReaders();
    if (readers.empty()) {
        std::cout << "No readers available." << std::endl;
        pauseExecution();
        return;
    }
    printReaders();
    std::cout << "READER WHOSE INFORMATION YOU WANT TO DELETE (1 to " << readers.size() << "): ";
    int index = readIntInRange(1, static_cast<int>(readers.size())) - 1;
    library_.removeReader(index);
    library_.saveReaders();
}

void MenuController::findReaderByIdNumber() const {
    std::cout << "CITIZEN ID NUMBER OF READERS IN LIBRARY\n";
    for (const Reader& reader : library_.getReaders()) {
        std::cout << reader.getIdNumber() << "\n";
    }

    std::string idNumber;
    do {
        idNumber = readNonEmptyLine("ID NUMBER OF READER (YOUR CITIZEN ID NUMBER) THAT YOU NEED TO FIND: ");
    } while (!isDigits(idNumber) || idNumber.size() != 12);

    const Reader* found = nullptr;
    for (const Reader& reader : library_.getReaders()) {
        if (reader.getIdNumber() == idNumber) {
            found = &reader;
            break;
        }
    }

    if (!found) {
        std::cout << "CAN'T FIND CITIZEN ID NUMBER!\n";
        pauseExecution();
        return;
    }

    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(10) << "CODE";
    std::cout << "  ||  " << std::setw(22) << "FULL NAME";
    std::cout << "  ||  " << std::setw(15) << "ID NUMBER";
    std::cout << "  ||   " << std::setw(8) << "DATEOFBIRTH";
    std::cout << "  ||  " << std::setw(3) << "GENDER";
    std::cout << "  ||  " << std::setw(30) << "EMAIL";
    std::cout << "  ||  " << std::setw(40) << "ADDRESS";
    std::cout << "  ||   " << std::setw(10) << "CREATING";
    std::cout << "  ||   " << std::setw(10) << "EXPIRING";
    std::cout << "  ||\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    std::cout << "|| " << std::left << std::setw(10) << found->getCode();
    std::cout << "  ||  " << std::setw(22) << found->getName();
    std::cout << "  ||  " << std::setw(15) << found->getIdNumber();
    std::cout << "  ||   " << std::setw(8) << found->getDob().toString('-');
    std::cout << "  ||  " << std::setw(7) << found->getGender();
    std::cout << "  ||  " << std::setw(30) << found->getEmail();
    std::cout << "  ||  " << std::setw(40) << found->getAddress();
    std::cout << "  ||   " << std::setw(10) << found->getCreateDate().toString('-');
    std::cout << "  ||   " << std::setw(10) << found->getExpireDate().toString('-');
    std::cout << "  ||\n";
    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    pauseExecution();
}

void MenuController::findBooksByReader() const {
    const auto& readers = library_.getReaders();
    if (readers.empty()) {
        std::cout << "No readers available." << std::endl;
        pauseExecution();
        return;
    }
    std::cout << "LIST NAME OF READERS\n";
    for (size_t i = 0; i < readers.size(); ++i) {
        std::cout << i + 1 << ". " << readers[i].getName() << "\n";
    }
    std::cout << "PLEASE CHOOSE 1 TO " << readers.size() << ": ";
    int index = readIntInRange(1, static_cast<int>(readers.size())) - 1;
    clearScreen();

    const auto& borrowed = readers[index].getBorrowedBooks();
    std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(12) << "ISBN";
    std::cout << "  || " << std::setw(20) << "NAME";
    std::cout << "  || " << std::setw(20) << "AUTHOR";
    std::cout << "  || " << std::setw(20) << "PUBLISHER";
    std::cout << "  || " << std::setw(5) << "YEAR";
    std::cout << "  || " << std::setw(15) << "TYPE";
    std::cout << "  ||\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    for (const BorrowRecord& record : borrowed) {
        const Book& book = record.book;
        std::cout << "|| " << std::left << std::setw(12) << book.getISBN();
        std::cout << "  || " << std::setw(20) << book.getTitle();
        std::cout << "  || " << std::setw(20) << book.getAuthor();
        std::cout << "  || " << std::setw(20) << book.getPublisher();
        std::cout << "  || " << std::setw(5) << book.getPublishingYear();
        std::cout << "  || " << std::setw(15) << book.getType();
        std::cout << "  ||\n";
        std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    }
    pauseExecution();
}

void MenuController::addBook() {
    std::string isbn;
    do {
        isbn = readNonEmptyLine("ISBN OF BOOK (10 NUMBERS): ");
    } while (!isDigits(isbn) || isbn.size() != 10);

    std::string title;
    do {
        title = readNonEmptyLine("NAME OF BOOK: ");
    } while (!isAlphaSpace(title));
    title = toUpper(title);

    std::string author;
    do {
        author = readNonEmptyLine("NAME OF AUTHOR: ");
    } while (!isAlphaSpace(author));
    author = toUpper(author);

    std::string publisher;
    do {
        publisher = readNonEmptyLine("PUBLISHER: ");
    } while (!isAlphaSpace(publisher));
    publisher = toUpper(publisher);

    std::cout << "FILL PUBLISHING YEAR: ";
    int year = readIntInRange(1900, 9999);

    std::string type;
    do {
        type = readNonEmptyLine("TYPE OF BOOK: ");
    } while (!isAlphaSpace(type));
    type = toUpper(type);

    std::cout << "PRICE OF BOOK: ";
    int price = readIntInRange(0, 10000000);

    std::cout << "THE QUANTITY: ";
    int quantity = readIntInRange(0, 1000000);

    Book book(isbn, title, author, publisher, year, type, price, quantity);
    library_.addBook(book);
    library_.saveBooks();
}

void MenuController::adjustBook() {
    const auto& books = library_.getBooks();
    if (books.empty()) {
        std::cout << "No books available." << std::endl;
        pauseExecution();
        return;
    }
    printBooks();
    std::cout << "PLEASE CHOOSE A BOOK TO ADJUST INFORMATION (1,2,..," << books.size() << "): ";
    int index = readIntInRange(1, static_cast<int>(books.size())) - 1;

    Book updated = library_.getBooks()[index];
    std::cout << "WHICH INFORMATION DO YOU NEED TO ADJUST?\n";
    std::cout << "1. ISBN OF BOOK\n";
    std::cout << "2. NAME OF BOOK\n";
    std::cout << "3. NAME OF AUTHOR\n";
    std::cout << "4. PUBLISHER\n";
    std::cout << "5. PUBLISHING YEAR\n";
    std::cout << "6. TYPE OF BOOK\n";
    std::cout << "7. PRICE OF BOOK\n";
    std::cout << "8. QUANTITY OF BOOK\n";
    int field = readIntInRange(1, 8);

    switch (field) {
        case 1: {
            std::string isbn;
            do {
                isbn = readNonEmptyLine("ISBN (10 NUMBERS): ");
            } while (!isDigits(isbn) || isbn.size() != 10);
            updated.setISBN(isbn);
            break;
        }
        case 2: {
            std::string title;
            do {
                title = readNonEmptyLine("NAME OF BOOK: ");
            } while (!isAlphaSpace(title));
            updated.setTitle(toUpper(title));
            break;
        }
        case 3: {
            std::string author;
            do {
                author = readNonEmptyLine("NAME OF AUTHOR: ");
            } while (!isAlphaSpace(author));
            updated.setAuthor(toUpper(author));
            break;
        }
        case 4: {
            std::string publisher;
            do {
                publisher = readNonEmptyLine("PUBLISHER: ");
            } while (!isAlphaSpace(publisher));
            updated.setPublisher(toUpper(publisher));
            break;
        }
        case 5:
            std::cout << "FILL PUBLISHING YEAR: ";
            updated.setPublishingYear(readIntInRange(1900, 9999));
            break;
        case 6: {
            std::string type;
            do {
                type = readNonEmptyLine("TYPE OF BOOK: ");
            } while (!isAlphaSpace(type));
            updated.setType(toUpper(type));
            break;
        }
        case 7:
            std::cout << "PRICE OF BOOK: ";
            updated.setPrice(readIntInRange(0, 10000000));
            break;
        case 8:
            std::cout << "THE QUANTITY: ";
            updated.setQuantity(readIntInRange(0, 1000000));
            break;
    }

    library_.updateBook(index, updated);
    library_.saveBooks();
}

void MenuController::deleteBook() {
    const auto& books = library_.getBooks();
    if (books.empty()) {
        std::cout << "No books available." << std::endl;
        pauseExecution();
        return;
    }
    printBooks();
    std::cout << "BOOK WHOSE INFORMATION YOU WANT TO DELETE (1 to " << books.size() << "): ";
    int index = readIntInRange(1, static_cast<int>(books.size())) - 1;
    library_.removeBook(index);
    library_.saveBooks();
}

void MenuController::findBookByISBN() const {
    std::string isbn = readNonEmptyLine("ISBN OF BOOK THAT YOU NEED TO FIND: ");
    const Book* found = nullptr;
    for (const Book& book : library_.getBooks()) {
        if (book.getISBN() == isbn) {
            found = &book;
            break;
        }
    }
    if (!found) {
        std::cout << "CAN'T FIND BOOK WITH ISBN!\n";
        pauseExecution();
        return;
    }

    std::cout << "|| " << std::left << std::setw(12) << "ISBN";
    std::cout << "  || " << std::setw(20) << "NAME";
    std::cout << "  || " << std::setw(20) << "AUTHOR";
    std::cout << "  || " << std::setw(20) << "PUBLISHER";
    std::cout << "  || " << std::setw(5) << "YEAR";
    std::cout << "  || " << std::setw(15) << "TYPE";
    std::cout << "  || " << std::setw(10) << "PRICE";
    std::cout << "  || " << std::setw(10) << "QUANTITY";
    std::cout << "  ||\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(12) << found->getISBN();
    std::cout << "  || " << std::setw(20) << found->getTitle();
    std::cout << "  || " << std::setw(20) << found->getAuthor();
    std::cout << "  || " << std::setw(20) << found->getPublisher();
    std::cout << "  || " << std::setw(5) << found->getPublishingYear();
    std::cout << "  || " << std::setw(15) << found->getType();
    std::cout << "  || " << std::setw(10) << found->getPrice();
    std::cout << "  || " << std::setw(10) << found->getQuantity();
    std::cout << "  ||\n";
    pauseExecution();
}

void MenuController::findBookByTitle() const {
    std::string title = readNonEmptyLine("NAME OF BOOK THAT YOU NEED TO FIND: ");
    title = toUpper(title);
    bool foundAny = false;

    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(12) << "ISBN";
    std::cout << "  || " << std::setw(20) << "NAME";
    std::cout << "  || " << std::setw(20) << "AUTHOR";
    std::cout << "  || " << std::setw(20) << "PUBLISHER";
    std::cout << "  || " << std::setw(5) << "YEAR";
    std::cout << "  || " << std::setw(15) << "TYPE";
    std::cout << "  || " << std::setw(10) << "PRICE";
    std::cout << "  || " << std::setw(10) << "QUANTITY";
    std::cout << "  ||\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";

    for (const Book& book : library_.getBooks()) {
        if (toUpper(book.getTitle()).find(title) != std::string::npos) {
            foundAny = true;
            std::cout << "|| " << std::left << std::setw(12) << book.getISBN();
            std::cout << "  || " << std::setw(20) << book.getTitle();
            std::cout << "  || " << std::setw(20) << book.getAuthor();
            std::cout << "  || " << std::setw(20) << book.getPublisher();
            std::cout << "  || " << std::setw(5) << book.getPublishingYear();
            std::cout << "  || " << std::setw(15) << book.getType();
            std::cout << "  || " << std::setw(10) << book.getPrice();
            std::cout << "  || " << std::setw(10) << book.getQuantity();
            std::cout << "  ||\n";
            std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        }
    }

    if (!foundAny) {
        std::cout << "CAN'T FIND BOOK WITH NAME!\n";
    }
    pauseExecution();
}

void MenuController::borrowBook(const Date& today) {
    const auto& readers = library_.getReaders();
    if (readers.empty()) {
        std::cout << "No readers available." << std::endl;
        pauseExecution();
        return;
    }
    for (const Reader& reader : readers) {
        std::cout << reader.getCode() << " - " << reader.getName() << "\n";
    }
    std::cout << "PLEASE CHOOSE YOUR STUDENT CODE BEFORE BORROWING BOOK (1 TO " << readers.size() << "): ";
    int readerIndex = readIntInRange(1, static_cast<int>(readers.size())) - 1;
    const std::string readerCode = readers[readerIndex].getCode();

    printBooks();
    std::cout << "WHICH BOOK DO YOU WANT TO BORROW? (1..." << library_.bookCount() << "): ";
    int bookIndex = readIntInRange(1, static_cast<int>(library_.bookCount())) - 1;

    if (borrowManager_.borrowBook(readerCode, static_cast<size_t>(bookIndex), today)) {
        std::cout << "BOOK BORROWED SUCCESSFULLY.\n";
    } else {
        std::cout << "CANNOT BORROW BOOK. CHECK AVAILABILITY OR BORROW LIMIT.\n";
    }
    pauseExecution();
}

void MenuController::returnBook(const Date& today) {
    const auto& readers = library_.getReaders();
    if (readers.empty()) {
        std::cout << "No readers available." << std::endl;
        pauseExecution();
        return;
    }
    for (size_t i = 0; i < readers.size(); ++i) {
        std::cout << i + 1 << ". " << readers[i].getName() << "\n";
    }
    std::cout << "PLEASE CHOOSE YOUR NAME (1 TO " << readers.size() << "): ";
    int readerIndex = readIntInRange(1, static_cast<int>(readers.size())) - 1;
    const Reader& reader = readers[readerIndex];
    const auto& borrowed = reader.getBorrowedBooks();
    if (borrowed.empty()) {
        std::cout << "This reader has no borrowed books.\n";
        pauseExecution();
        return;
    }

    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    std::cout << "|| " << std::left << std::setw(12) << "ISBN";
    std::cout << "  || " << std::setw(20) << "NAME";
    std::cout << "  || " << std::setw(20) << "AUTHOR";
    std::cout << "  || " << std::setw(20) << "PUBLISHER";
    std::cout << "  || " << std::setw(15) << "PUBLISHINGYEAR";
    std::cout << "  || " << std::setw(15) << "TYPE";
    std::cout << "  ||  " << std::setw(7) << "BORROW";
    std::cout << "  ||   " << std::setw(7) << "RETURN";
    std::cout << "  ||\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    for (const BorrowRecord& record : borrowed) {
        const Book& book = record.book;
        std::cout << "|| " << std::left << std::setw(12) << book.getISBN();
        std::cout << "  || " << std::setw(20) << book.getTitle();
        std::cout << "  || " << std::setw(20) << book.getAuthor();
        std::cout << "  || " << std::setw(20) << book.getPublisher();
        std::cout << "  || " << std::setw(15) << book.getPublishingYear();
        std::cout << "  || " << std::setw(15) << book.getType();
        std::cout << "  || " << std::setw(7) << record.borrowDate.toString('/');
        std::cout << "  ||   " << std::setw(7) << record.dueDate.toString('/');
        std::cout << "  ||\n";
        std::cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }

    std::cout << "PLEASE CHOOSE THE BOOK YOU RETURN (1 TO " << borrowed.size() << "): ";
    int borrowIndex = readIntInRange(1, static_cast<int>(borrowed.size())) - 1;
    std::cout << "PLEASE CHOOSE \n";
    std::cout << "1. LOSE BOOK\n";
    std::cout << "2. RETURN BOOK\n";
    int action = readIntInRange(1, 2);
    long fee = 0;
    bool ok = false;
    if (action == 2) {
        ok = borrowManager_.returnBook(reader.getCode(), static_cast<size_t>(borrowIndex), today, fee);
        if (ok) {
            if (fee <= 0) {
                std::cout << "YOU DON'T HAVE TO PAY FEE!\n";
            } else {
                std::cout << "YOU HAVE BEEN LATE " << fee / 5000 << ". YOU HAVE TO PAY " << fee << " VND\n";
            }
        } else {
            std::cout << "RETURN OPERATION FAILED.\n";
        }
    } else {
        ok = borrowManager_.loseBook(reader.getCode(), static_cast<size_t>(borrowIndex), fee);
        if (ok) {
            std::cout << "YOU HAVE TO PAY " << fee << " VND\n";
        } else {
            std::cout << "LOSS OPERATION FAILED.\n";
        }
    }
    if (ok) {
        library_.saveBooks();
    }
    pauseExecution();
}
