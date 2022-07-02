#ifndef MEDIUM_H
#define MEDIUM_H

#include <QObject>
#include <ostream>
#include <string>

class Medium : public QObject
{
    Q_OBJECT
public:
    explicit Medium(QObject *parent = nullptr);
    std::string GetTitle() {
        return this->_title;
    }
    void SetTitle(std::string title) {
        this->_title = title;
    }
    std::string GetDescription() {
        return this->_description;
    }
    void SetDescription(std::string description) {
        this->_description = description;
    }
    virtual std::ostream &Show(std::ostream &os);

private:
    std::string _title;
    std::string _description;
};

#endif // MEDIUM_H
