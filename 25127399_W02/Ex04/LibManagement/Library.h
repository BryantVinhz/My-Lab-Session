#pragma once

#include <string>
#include <vector>

#include "book.h"
#include "reader.h"

class Library {
private:
    std::vector<Book> books_;
    std::vector<Reader> readers_;
    std::string bookFilename_;
    std::string readerFilename_;

public:
    Library(const std::string& bookFilename = "listBook.txt",
            const std::string& readerFilename = "listReader.txt");

    void load();
    void save();
    void loadBooks();
    void saveBooks() const;
    void loadReaders();
    void saveReaders() const;

    const std::vector<Book>& getBooks() const;
    std::vector<Book>& getBooks();
    const std::vector<Reader>& getReaders() const;
    std::vector<Reader>& getReaders();

    size_t bookCount() const;
    size_t readerCount() const;

    Book* findBookByISBN(const std::string& isbn);
    std::vector<Book*> findBooksByTitle(const std::string& title);

    Reader* findReaderByCode(const std::string& code);
    Reader* findReaderByIdNumber(const std::string& idNumber);
    std::vector<Reader*> findReadersByName(const std::string& name);

    void addBook(const Book& book);
    void updateBook(size_t index, const Book& book);
    void removeBook(size_t index);

    void addReader(const Reader& reader);
    void updateReader(size_t index, const Reader& reader);
    void removeReader(size_t index);
};
