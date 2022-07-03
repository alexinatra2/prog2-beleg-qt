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
    int GetLength() {
        return this->_length;
    }
    void SetLength(int length) {
        this->_length = length;
    }
    std::ostream &Show(std::ostream &os) {
        os << "type: " << GetType() << '\n';
        os << "title: " << this->GetTitle() << '\n';
        os << "age rating: " << this->GetAgeRestriction() << '\n';
        os << "length: " << this->GetLength();
        os << "description: " << this->GetDescription();
        return os;
    }

private:
    int _ageRestriction;
    int _length;
};

#endif // VIDEOMEDIUM_H
