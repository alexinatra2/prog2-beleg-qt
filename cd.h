#ifndef CD_H
#define CD_H

#include "medium.h"

class Cd : public Medium
{
public:
    explicit Cd(QObject *parent = nullptr);
};

#endif // CD_H
