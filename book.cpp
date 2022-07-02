#include "book.h"

Book::Book(QObject *parent)
    : Medium{parent}
{
    this->_type = BOOK;
}
