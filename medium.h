#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>

class Medium : public QObject
{
    Q_OBJECT
public:
    explicit Medium(QObject *parent = nullptr);

};

#endif // MEDIUM_H
