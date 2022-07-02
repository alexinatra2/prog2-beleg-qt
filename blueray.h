#ifndef BLUERAY_H
#define BLUERAY_H

#include "videomedium.h"

class Blueray : public VideoMedium
{
public:
    explicit Blueray(QObject *parent = nullptr);
};

#endif // BLUERAY_H
