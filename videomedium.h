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
    virtual std::ostream &Show(std::ostream &os) {
        return os;
    }

private:
    int _ageRestriction;
};

#endif // VIDEOMEDIUM_H
