#include "book.h"

#include <sstream>
#include <string>
#include <vector>

Book::Book()
    : publishingYear_(0), price_(0), quantity_(0) {
}

Book::Book(const std::string& isbn,
           const std::string& title,
           const std::string& author,
           const std::string& publisher,
           int publishingYear,
           const std::string& type,
           long price,
           int quantity)
    : isbn_(isbn),
      title_(title),
      author_(author),
      publisher_(publisher),
      publishingYear_(publishingYear),
      type_(type),
      price_(price),
      quantity_(quantity) {
}

const std::string& Book::getISBN() const {
    return isbn_;
}

const std::string& Book::getTitle() const {
    return title_;
}

const std::string& Book::getAuthor() const {
    return author_;
}

const std::string& Book::getPublisher() const {
    return publisher_;
}

int Book::getPublishingYear() const {
    return publishingYear_;
}

const std::string& Book::getType() const {
    return type_;
}

long Book::getPrice() const {
    return price_;
}

int Book::getQuantity() const {
    return quantity_;
}

void Book::setISBN(const std::string& isbn) {
    isbn_ = isbn;
}

void Book::setTitle(const std::string& title) {
    title_ = title;
}

void Book::setAuthor(const std::string& author) {
    author_ = author;
}

void Book::setPublisher(const std::string& publisher) {
    publisher_ = publisher;
}

void Book::setPublishingYear(int publishingYear) {
    publishingYear_ = publishingYear;
}

void Book::setType(const std::string& type) {
    type_ = type;
}

void Book::setPrice(long price) {
    price_ = price;
}

void Book::setQuantity(int quantity) {
    quantity_ = quantity;
}

void Book::incrementQuantity(int amount) {
    quantity_ += amount;
}

void Book::decrementQuantity(int amount) {
    quantity_ -= amount;
    if (quantity_ < 0) {
        quantity_ = 0;
    }
}

std::string Book::toCsv() const {
    std::ostringstream output;
    output << isbn_ << ','
           << title_ << ','
           << author_ << ','
           << publisher_ << ','
           << publishingYear_ << ','
           << type_ << ','
           << price_ << ','
           << quantity_;
    return output.str();
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

Book Book::fromCsv(const std::string& csvLine) {
    std::vector<std::string> tokens = splitCsvLine(csvLine);
    if (tokens.size() < 8) {
        return Book();
    }

    int year = 0;
    long price = 0;
    int quantity = 0;

    try {
        year = std::stoi(tokens[4]);
    } catch (...) {
        year = 0;
    }

    try {
        price = std::stol(tokens[6]);
    } catch (...) {
        price = 0;
    }

    try {
        quantity = std::stoi(tokens[7]);
    } catch (...) {
        quantity = 0;
    }

    return Book(tokens[0], tokens[1], tokens[2], tokens[3], year, tokens[5], price, quantity);
}
