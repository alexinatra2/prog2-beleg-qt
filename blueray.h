#ifndef BLUERAY_H
#define BLUERAY_H

#include "videomedium.h"

class Blueray : public Medium
{
public:
    explicit Blueray(QObject *parent = nullptr);
};

#endif // BLUERAY_H
