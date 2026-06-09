#pragma once

#include "Library.h"
#include "reader.h"

class Statistics {
private:
    const Library& library_;

public:
    explicit Statistics(const Library& library);

    void printTotalBooks() const;
    void printBooksByType() const;
    void printTotalReaders() const;
    void printGenderDistribution() const;
    void printBooksBorrowed() const;
    void printLateReaders(const Date& today) const;
};
