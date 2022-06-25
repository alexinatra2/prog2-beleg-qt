#ifndef BOOK_H
#define BOOK_H

#include "printmedium.h"

class Book : public PrintMedium
{
public:
    explicit Book(QObject *parent = nullptr);
};

#endif // BOOK_H
