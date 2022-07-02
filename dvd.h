#ifndef DVD_H
#define DVD_H

#include "videomedium.h"

class Dvd : public VideoMedium
{
public:
    explicit Dvd(QObject *parent = nullptr);
    std::ostream &Show(std::ostream &os) {
        return os;
    }

private:
};

#endif // DVD_H
