#include "dvd.h"

Dvd::Dvd(QObject *parent)
    : Medium{parent}
{
    setType(DVD);
}

QString Dvd::details()
{
    std::stringstream ss;
    ss << "title: " << title().toStdString() << '\n';
    ss << "description: " << description().toStdString() << '\n';
    ss << "age rating: " << ageRating() << '\n';
    ss << "length: " << length();
    return QString::fromStdString(ss.str());
}

int Dvd::length() const
{
    return _length;
}

void Dvd::setLength(int newLength)
{
    _length = newLength;
}

int Dvd::ageRating() const
{
    return _ageRating;
}

void Dvd::setAgeRating(int newAgeRating)
{
    _ageRating = newAgeRating;
}

bool Dvd::isAllowedToBeBorrowedBy(User *user) {
    return available() && user->age() >= this->ageRating();
}
