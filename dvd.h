#ifndef DVD_H
#define DVD_H

#include "medium.h"

class Dvd : public Medium
{
public:
    explicit Dvd(QObject *parent = nullptr);

    int length() const;
    void setLength(int newLength);
    int ageRating() const;
    void setAgeRating(int newAgeRating);

private:
    int _length;
    int _ageRating;
};

#endif // DVD_H
