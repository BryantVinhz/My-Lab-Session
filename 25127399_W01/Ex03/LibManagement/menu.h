#pragma once

#include <string>

#include "Library.h"
#include "BorrowManager.h"
#include "statistics.h"

class MenuController {
private:
    Library library_;
    BorrowManager borrowManager_;
    Statistics statistics_;

public:
    MenuController();
    void run();

private:
    Date inputCurrentDate() const;
    int readIntInRange(int minValue, int maxValue) const;
    std::string readLine() const;
    std::string readNonEmptyLine(const std::string& prompt) const;
    void pauseExecution() const;
    void clearScreen() const;

    void showMainMenu() const;
    void showReaderMenu() const;
    void showBookMenu() const;
    void showStatisticsMenu() const;

    void runReaderMenu();
    void runBookMenu();
    void runStatisticsMenu() const;

    void printReaders() const;
    void printBooks() const;
    void addReader();
    void adjustReader();
    void deleteReader();
    void findReaderByIdNumber() const;
    void findBooksByReader() const;

    void addBook();
    void adjustBook();
    void deleteBook();
    void findBookByISBN() const;
    void findBookByTitle() const;

    void borrowBook(const Date& today);
    void returnBook(const Date& today);
};
