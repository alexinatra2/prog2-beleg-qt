#ifndef BOOK_H
#define BOOK_H

#include "medium.h"

class Book : public Medium
{
public:
    explicit Book(QObject *parent = nullptr);
    QString details();

    const QString &author() const;
    void setAuthor(const QString &newAuthor);
    int pages() const;
    void setPages(int newPages);
    int chapters() const;
    void setChapters(int newChapters);

private:
    QString _author;
    unsigned int _pages;
    unsigned int _chapters;
};

#endif // BOOK_H
