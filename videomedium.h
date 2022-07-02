#ifndef VIDEOMEDIUM_H
#define VIDEOMEDIUM_H

#include "medium.h"

class VideoMedium : public Medium
{
public:
    explicit VideoMedium(QObject *parent = nullptr);
    int GetAgeRestriction() {
        return this->_ageRestriction;
    }
    void SetAgeRestriction(int ageRestriction) {
        this->_ageRestriction = ageRestriction;
    }

private:
    int _ageRestriction;
};

#endif // VIDEOMEDIUM_H
