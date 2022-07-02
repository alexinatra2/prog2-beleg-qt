#ifndef CD_H
#define CD_H

#include "medium.h"

class Cd : public Medium
{
public:
    explicit Cd(QObject *parent = nullptr);
    std::ostream &Show(std::ostream &os) {
        return os;
    }
};

#endif // CD_H
