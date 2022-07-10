#include "medium.h"

Medium::Medium(QObject *parent)
    : QObject{parent}
{

}

bool Medium::isAllowedToBeBorrowedBy(User *user)
{
    return available();
}

const QString &Medium::title() const
{
    return _title;
}

void Medium::setTitle(const QString &newTitle)
{
    _title = newTitle;
}

const QString &Medium::description() const
{
    return _description;
}

void Medium::setDescription(const QString &newDescription)
{
    _description = newDescription;
}

void Medium::setBorrower(User *newBorrower)
{
    _borrower = newBorrower;
}

User *Medium::borrower() const
{
    return _borrower;
}

bool Medium::available() const
{
    return _borrower == nullptr;
}

MediumType Medium::type() const
{
    return _type;
}

void Medium::setType(MediumType newType)
{
    _type = newType;
}

const QString Medium::mediumTypeString(MediumType type)
{
    switch (type) {
    case BOOK:
        return "book";
    case CD:
        return "cd";
    case DVD:
        return "dvd";
    }
}
