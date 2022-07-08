#ifndef CD_H
#define CD_H

#include "medium.h"
#include "qdatetime.h"

class Cd : public Medium
{
public:
    explicit Cd(QObject *parent = nullptr);
    QString details();

    int totalLength() const;
    void setTotalLength(int newTotalLength);
    int numberOfTracks() const;
    void setNumberOfTracks(int newNumberOfTracks);
    const QDate &releaseDate() const;
    void setReleaseDate(const QDate &newReleaseDate);

private:
    unsigned int _totalLength;
    unsigned int _numberOfTracks;
    QDate _releaseDate;

};

#endif // CD_H
