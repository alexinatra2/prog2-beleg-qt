#ifndef BLUERAY_H
#define BLUERAY_H

#include "videomedium.h"

class Blueray : public VideoMedium
{
public:
    explicit Blueray(QObject *parent = nullptr);
    std::ostream &Show(std::ostream &os) {
        return os;
    }
};

#endif // BLUERAY_H
