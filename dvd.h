#ifndef DVD_H
#define DVD_H

#include "videomedium.h"

class Dvd : public VideoMedium
{
public:
    explicit Dvd(QObject *parent = nullptr);

private:
};

#endif // DVD_H
