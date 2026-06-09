#include "Library.h"

#include <fstream>
#include <sstream>

Library::Library(const std::string& bookFilename, const std::string& readerFilename)
    : bookFilename_(bookFilename), readerFilename_(readerFilename) {
}

void Library::load() {
    loadBooks();
    loadReaders();
}

void Library::save() {
    saveBooks();
    saveReaders();
}

void Library::loadBooks() {
    books_.clear();
    std::ifstream input(bookFilename_);
    if (!input.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        books_.push_back(Book::fromCsv(line));
    }
}

void Library::saveBooks() const {
    std::ofstream output(bookFilename_, std::ios::trunc);
    if (!output.is_open()) {
        return;
    }

    for (size_t i = 0; i < books_.size(); ++i) {
        output << books_[i].toCsv();
        if (i + 1 < books_.size()) {
            output << '\n';
        }
    }
}

void Library::loadReaders() {
    readers_.clear();
    std::ifstream input(readerFilename_);
    if (!input.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(input, line)) {
        if (line.empty()) {
            continue;
        }
        readers_.push_back(Reader::fromCsv(line));
    }
}

void Library::saveReaders() const {
    std::ofstream output(readerFilename_, std::ios::trunc);
    if (!output.is_open()) {
        return;
    }

    for (size_t i = 0; i < readers_.size(); ++i) {
        output << readers_[i].toCsv();
        if (i + 1 < readers_.size()) {
            output << '\n';
        }
    }
}

const std::vector<Book>& Library::getBooks() const {
    return books_;
}

std::vector<Book>& Library::getBooks() {
    return books_;
}

const std::vector<Reader>& Library::getReaders() const {
    return readers_;
}

std::vector<Reader>& Library::getReaders() {
    return readers_;
}

size_t Library::bookCount() const {
    return books_.size();
}

size_t Library::readerCount() const {
    return readers_.size();
}

Book* Library::findBookByISBN(const std::string& isbn) {
    for (Book& book : books_) {
        if (book.getISBN() == isbn) {
            return &book;
        }
    }
    return nullptr;
}

std::vector<Book*> Library::findBooksByTitle(const std::string& title) {
    std::vector<Book*> results;
    for (Book& book : books_) {
        if (book.getTitle() == title) {
            results.push_back(&book);
        }
    }
    return results;
}

Reader* Library::findReaderByCode(const std::string& code) {
    for (Reader& reader : readers_) {
        if (reader.getCode() == code) {
            return &reader;
        }
    }
    return nullptr;
}

Reader* Library::findReaderByIdNumber(const std::string& idNumber) {
    for (Reader& reader : readers_) {
        if (reader.getIdNumber() == idNumber) {
            return &reader;
        }
    }
    return nullptr;
}

std::vector<Reader*> Library::findReadersByName(const std::string& name) {
    std::vector<Reader*> results;
    for (Reader& reader : readers_) {
        if (reader.getName() == name) {
            results.push_back(&reader);
        }
    }
    return results;
}

void Library::addBook(const Book& book) {
    books_.push_back(book);
}

void Library::updateBook(size_t index, const Book& book) {
    if (index < books_.size()) {
        books_[index] = book;
    }
}

void Library::removeBook(size_t index) {
    if (index < books_.size()) {
        books_.erase(books_.begin() + static_cast<std::ptrdiff_t>(index));
    }
}

void Library::addReader(const Reader& reader) {
    readers_.push_back(reader);
}

void Library::updateReader(size_t index, const Reader& reader) {
    if (index < readers_.size()) {
        readers_[index] = reader;
    }
}

void Library::removeReader(size_t index) {
    if (index < readers_.size()) {
        readers_.erase(readers_.begin() + static_cast<std::ptrdiff_t>(index));
    }
}
