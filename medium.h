#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>
#include <QString>

class Medium : public QObject
{
    Q_OBJECT
public:
    explicit Medium(QObject *parent = nullptr);
    virtual QString details() {
        return QString::fromStdString("");
    }

    const QString &title() const;
    void setTitle(const QString &newTitle);
    const QString &description() const;
    void setDescription(const QString &newDescription);
    bool available() const;
    void setAvailable(bool newAvailable);

signals:
    void medium_submitted();

private:
    QString _title;
    QString _description;
    bool _available;
};

#endif // MEDIUM_H
