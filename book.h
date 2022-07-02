#ifndef BOOK_H
#define BOOK_H

#include "medium.h"

class Book : public Medium
{
public:
    explicit Book(QObject *parent = nullptr);
    std::ostream &Show(std::ostream &os) {
        return os;
    }
};

#endif // BOOK_H
