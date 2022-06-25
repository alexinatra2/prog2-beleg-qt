#ifndef VIDEOMEDIUM_H
#define VIDEOMEDIUM_H

#include "medium.h"

class VideoMedium : public Medium
{
public:
    explicit VideoMedium(QObject *parent = nullptr);
};

#endif // VIDEOMEDIUM_H
