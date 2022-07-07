#include "dvd.h"

Dvd::Dvd(QObject *parent)
    : Medium{parent}
{

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
