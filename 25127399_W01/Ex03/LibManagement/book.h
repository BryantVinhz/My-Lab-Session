#pragma once

#include <string>

class Book {
private:
    std::string isbn_;
    std::string title_;
    std::string author_;
    std::string publisher_;
    int publishingYear_;
    std::string type_;
    long price_;
    int quantity_;

public:
    Book();
    Book(const std::string& isbn,
         const std::string& title,
         const std::string& author,
         const std::string& publisher,
         int publishingYear,
         const std::string& type,
         long price,
         int quantity);

    const std::string& getISBN() const;
    const std::string& getTitle() const;
    const std::string& getAuthor() const;
    const std::string& getPublisher() const;
    int getPublishingYear() const;
    const std::string& getType() const;
    long getPrice() const;
    int getQuantity() const;

    void setISBN(const std::string& isbn);
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setPublisher(const std::string& publisher);
    void setPublishingYear(int publishingYear);
    void setType(const std::string& type);
    void setPrice(long price);
    void setQuantity(int quantity);

    void incrementQuantity(int amount = 1);
    void decrementQuantity(int amount = 1);

    std::string toCsv() const;
    static Book fromCsv(const std::string& csvLine);
};
