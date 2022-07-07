#include "book.h"

Book::Book(QObject *parent)
    : Medium{parent}
{

}

const QString &Book::author() const
{
    return _author;
}

void Book::setAuthor(const QString &newAuthor)
{
    _author = newAuthor;
}

int Book::pages() const
{
    return _pages;
}

void Book::setPages(int newPages)
{
    _pages = newPages;
}

int Book::chapters() const
{
    return _chapters;
}

void Book::setChapters(int newChapters)
{
    _chapters = newChapters;
}
