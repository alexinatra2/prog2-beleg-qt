#ifndef DVD_H
#define DVD_H

#include "medium.h"

class Dvd : public Medium
{
public:
    explicit Dvd(QObject *parent = nullptr);
};

#endif // DVD_H
