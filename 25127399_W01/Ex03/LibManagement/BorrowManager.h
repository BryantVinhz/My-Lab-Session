#pragma once

#include <string>

#include "Library.h"
#include "reader.h"

class BorrowManager {
private:
    Library& library_;
    static int daysInMonth(int month, int year);
    static bool isLeapYear(int year);
    static int daysBetween(const Date& from, const Date& to);

public:
    explicit BorrowManager(Library& library);

    Date calculateDueDate(const Date& borrowDate) const;
    long calculateLateFee(const Date& dueDate, const Date& actualDate) const;
    long calculateLossFee(const Book& book) const;

    bool borrowBook(const std::string& readerCode, size_t bookIndex, const Date& today);
    bool returnBook(const std::string& readerCode, size_t borrowIndex, const Date& today, long& fee);
    bool loseBook(const std::string& readerCode, size_t borrowIndex, long& fee);
};
