#ifndef CD_H
#define CD_H

#include "medium.h"
#include "qdatetime.h"

class Cd : public Medium
{
public:
    explicit Cd(QObject *parent = nullptr);

    int totalLength() const;
    void setTotalLength(int newTotalLength);
    int numberOfTracks() const;
    void setNumberOfTracks(int newNumberOfTracks);
    const QDate &releaseDate() const;
    void setReleaseDate(const QDate &newReleaseDate);

private:
    int _totalLength;
    int _numberOfTracks;
    QDate _releaseDate;

};

#endif // CD_H
