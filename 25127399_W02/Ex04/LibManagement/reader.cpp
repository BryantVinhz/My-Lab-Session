#include "reader.h"

#include <sstream>
#include <string>
#include <vector>

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {
}

int Date::day() const {
    return day_;
}

int Date::month() const {
    return month_;
}

int Date::year() const {
    return year_;
}

void Date::setDay(int day) {
    day_ = day;
}

void Date::setMonth(int month) {
    month_ = month;
}

void Date::setYear(int year) {
    year_ = year;
}

std::string Date::toString(char separator) const {
    std::ostringstream output;
    output << day_ << separator << month_ << separator << year_;
    return output.str();
}

Date Date::fromString(const std::string& source, char separator) {
    std::vector<std::string> tokens;
    std::stringstream stream(source);
    std::string token;
    while (std::getline(stream, token, separator)) {
        tokens.push_back(token);
    }

    int day = 0;
    int month = 0;
    int year = 0;

    if (tokens.size() >= 1) {
        try {
            day = std::stoi(tokens[0]);
        } catch (...) {
            day = 0;
        }
    }

    if (tokens.size() >= 2) {
        try {
            month = std::stoi(tokens[1]);
        } catch (...) {
            month = 0;
        }
    }

    if (tokens.size() >= 3) {
        try {
            year = std::stoi(tokens[2]);
        } catch (...) {
            year = 0;
        }
    }

    return Date(day, month, year);
}

Date Date::addYears(int years) const {
    return Date(day_, month_, year_ + years);
}

bool Date::operator<(const Date& other) const {
    if (year_ != other.year_) {
        return year_ < other.year_;
    }
    if (month_ != other.month_) {
        return month_ < other.month_;
    }
    return day_ < other.day_;
}

bool Date::operator==(const Date& other) const {
    return day_ == other.day_ && month_ == other.month_ && year_ == other.year_;
}

Reader::Reader()
    : dob_(), gender_(""), createDate_(), expireDate_() {
}

Reader::Reader(const std::string& code,
               const std::string& name,
               const std::string& idNumber,
               const Date& dob,
               const std::string& gender,
               const std::string& email,
               const std::string& address,
               const Date& createDate,
               const Date& expireDate)
    : code_(code),
      name_(name),
      idNumber_(idNumber),
      dob_(dob),
      gender_(gender),
      email_(email),
      address_(address),
      createDate_(createDate),
      expireDate_(expireDate) {
}

const std::string& Reader::getCode() const {
    return code_;
}

const std::string& Reader::getName() const {
    return name_;
}

const std::string& Reader::getIdNumber() const {
    return idNumber_;
}

const Date& Reader::getDob() const {
    return dob_;
}

const std::string& Reader::getGender() const {
    return gender_;
}

const std::string& Reader::getEmail() const {
    return email_;
}

const std::string& Reader::getAddress() const {
    return address_;
}

const Date& Reader::getCreateDate() const {
    return createDate_;
}

const Date& Reader::getExpireDate() const {
    return expireDate_;
}

const std::vector<BorrowRecord>& Reader::getBorrowedBooks() const {
    return borrowedBooks_;
}

void Reader::setCode(const std::string& code) {
    code_ = code;
}

void Reader::setName(const std::string& name) {
    name_ = name;
}

void Reader::setIdNumber(const std::string& idNumber) {
    idNumber_ = idNumber;
}

void Reader::setDob(const Date& dob) {
    dob_ = dob;
}

void Reader::setGender(const std::string& gender) {
    gender_ = gender;
}

void Reader::setEmail(const std::string& email) {
    email_ = email;
}

void Reader::setAddress(const std::string& address) {
    address_ = address;
}

void Reader::setCreateDate(const Date& createDate) {
    createDate_ = createDate;
}

void Reader::setExpireDate(const Date& expireDate) {
    expireDate_ = expireDate;
}

bool Reader::canBorrow() const {
    return static_cast<int>(borrowedBooks_.size()) < 6;
}

int Reader::borrowedCount() const {
    return static_cast<int>(borrowedBooks_.size());
}

void Reader::borrowBook(const Book& book, const Date& borrowDate, const Date& dueDate) {
    if (canBorrow()) {
        BorrowRecord record{book, borrowDate, dueDate};
        borrowedBooks_.push_back(record);
    }
}

BorrowRecord Reader::returnBook(size_t index) {
    BorrowRecord record;
    if (index < borrowedBooks_.size()) {
        record = borrowedBooks_[index];
        borrowedBooks_.erase(borrowedBooks_.begin() + static_cast<std::ptrdiff_t>(index));
    }
    return record;
}

bool Reader::hasOverdue(const Date& today) const {
    for (const BorrowRecord& record : borrowedBooks_) {
        if (record.dueDate < today && !(today == record.dueDate)) {
            return true;
        }
    }
    return false;
}

static std::vector<std::string> splitCsvLine(const std::string& csvLine) {
    std::vector<std::string> tokens;
    std::stringstream stream(csvLine);
    std::string token;
    while (std::getline(stream, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

std::string Reader::toCsv() const {
    std::ostringstream output;
    output << code_ << ','
           << name_ << ','
           << idNumber_ << ','
           << dob_.toString('-') << ','
           << (gender_ == "MALE" ? "1" : "0") << ','
           << email_ << ','
           << address_ << ','
           << createDate_.toString('-');
    return output.str();
}

Reader Reader::fromCsv(const std::string& csvLine) {
    std::vector<std::string> tokens = splitCsvLine(csvLine);
    if (tokens.size() < 8) {
        return Reader();
    }

    Date dob = Date::fromString(tokens[3], '-');
    Date createDate = Date::fromString(tokens[7], '-');
    Date expireDate = createDate.addYears(4);
    std::string gender = (tokens[4] == "1" ? "MALE" : "FEMALE");

    return Reader(tokens[0], tokens[1], tokens[2], dob, gender, tokens[5], tokens[6], createDate, expireDate);
}
