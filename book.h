#ifndef BOOK_H
#define BOOK_H

#include "medium.h"
#include <string>

class Book : public Medium
{
public:
    explicit Book(QObject *parent = nullptr);
    std::string GetAuthor() {
        return this->_author;
    }
    void SetAuthor(std::string author) {
        this->_author = author;
    }
    std::string GetSubTitle() {
        return this->_subTitle == nullptr ? "" : *this->_subTitle;
    }
    void SetSubTitle(std::string *subTitle) {
        this->_subTitle = subTitle;
    }
    int GetPages() {
        return this->_pages;
    }
    void SetPages(int pages) {
        this->_pages = pages;
    }
    std::ostream &Show(std::ostream &os) {
        os << "type: " << GetType() << '\n';
        os << "title: " << GetTitle() << '\n';
        os << "subtitle: " << GetSubTitle() << '\n';
        os << "author: " << GetAuthor() << '\n';
        os << "number of pages: " << GetPages() << '\n';
        os << "description: " << GetDescription();
        return os;
    }

private:
    std::string _author;
    std::string *_subTitle;
    int _pages;
};

#endif // BOOK_H
