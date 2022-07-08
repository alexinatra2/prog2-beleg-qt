#include "cd.h"

Cd::Cd(QObject *parent)
    : Medium{parent}
{

}

QString Cd::details()
{
    std::stringstream ss;
    ss << "title: " << title().toStdString() << '\n';
    ss << "description: " << description().toStdString() << '\n';
    ss << "total length: " << totalLength() << '\n';
    ss << "number of tracks: " << numberOfTracks() << '\n';
    ss << "release date: " << releaseDate().toString().toStdString();
    return QString::fromStdString(ss.str());
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
