#include "cd.h"

Cd::Cd(QObject *parent)
    : Medium{parent}
{

}

int Cd::totalLength() const
{
    return _totalLength;
}

void Cd::setTotalLength(int newTotalLength)
{
    _totalLength = newTotalLength;
}

int Cd::numberOfTracks() const
{
    return _numberOfTracks;
}

void Cd::setNumberOfTracks(int newNumberOfTracks)
{
    _numberOfTracks = newNumberOfTracks;
}

const QDate &Cd::releaseDate() const
{
    return _releaseDate;
}

void Cd::setReleaseDate(const QDate &newReleaseDate)
{
    _releaseDate = newReleaseDate;
}
