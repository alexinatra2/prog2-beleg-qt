#include "blueray.h"

Blueray::Blueray(QObject *parent)
    : VideoMedium{parent}
{
    this->_type = BLUERAY;
}
