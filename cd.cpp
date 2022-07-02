#include "cd.h"

Cd::Cd(QObject *parent)
    : Medium{parent}
{
    this->_type = CD;
}
