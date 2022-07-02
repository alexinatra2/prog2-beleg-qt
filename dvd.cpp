#include "dvd.h"

Dvd::Dvd(QObject *parent)
    : VideoMedium{parent}
{
    this->_type = DVD;
}
