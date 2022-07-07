#include "medium.h"

Medium::Medium(QObject *parent)
    : QObject{parent}
{

}

const QString &Medium::title() const
{
    return _title;
}

void Medium::setTitle(const QString &newTitle)
{
    _title = newTitle;
}

const QString &Medium::description() const
{
    return _description;
}

void Medium::setDescription(const QString &newDescription)
{
    _description = newDescription;
}

bool Medium::available() const
{
    return _available;
}

void Medium::setAvailable(bool newAvailable)
{
    _available = newAvailable;
}
