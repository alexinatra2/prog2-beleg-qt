#ifndef BOOK_H
#define BOOK_H

#include "medium.h"

class Book : public Medium
{
public:
    explicit Book(QObject *parent = nullptr);
};

#endif // BOOK_H
