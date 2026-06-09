#pragma once

#include <string>
#include <vector>

#include "book.h"

class Date {
private:
    int day_;
    int month_;
    int year_;

public:
    Date(int day = 0, int month = 0, int year = 0);

    int day() const;
    int month() const;
    int year() const;

    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    std::string toString(char separator = '-') const;
    static Date fromString(const std::string& source, char separator = '-');
    Date addYears(int years) const;

    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
};

struct BorrowRecord {
    Book book;
    Date borrowDate;
    Date dueDate;
};

class Reader {
private:
    std::string code_;
    std::string name_;
    std::string idNumber_;
    Date dob_;
    std::string gender_;
    std::string email_;
    std::string address_;
    Date createDate_;
    Date expireDate_;
    std::vector<BorrowRecord> borrowedBooks_;

public:
    Reader();
    Reader(const std::string& code,
           const std::string& name,
           const std::string& idNumber,
           const Date& dob,
           const std::string& gender,
           const std::string& email,
           const std::string& address,
           const Date& createDate,
           const Date& expireDate);

    const std::string& getCode() const;
    const std::string& getName() const;
    const std::string& getIdNumber() const;
    const Date& getDob() const;
    const std::string& getGender() const;
    const std::string& getEmail() const;
    const std::string& getAddress() const;
    const Date& getCreateDate() const;
    const Date& getExpireDate() const;
    const std::vector<BorrowRecord>& getBorrowedBooks() const;

    void setCode(const std::string& code);
    void setName(const std::string& name);
    void setIdNumber(const std::string& idNumber);
    void setDob(const Date& dob);
    void setGender(const std::string& gender);
    void setEmail(const std::string& email);
    void setAddress(const std::string& address);
    void setCreateDate(const Date& createDate);
    void setExpireDate(const Date& expireDate);

    bool canBorrow() const;
    int borrowedCount() const;

    void borrowBook(const Book& book, const Date& borrowDate, const Date& dueDate);
    BorrowRecord returnBook(size_t index);
    bool hasOverdue(const Date& today) const;

    std::string toCsv() const;
    static Reader fromCsv(const std::string& csvLine);
};
