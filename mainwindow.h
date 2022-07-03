#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "medium.h"
#include "user.h"

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addMedium();
    void removeMedium() { qDebug() << "test"; }
    void editMedium() { qDebug() << "test"; }
    void borrowMedium() { qDebug() << "test"; }
    void returnMedium() { qDebug() << "test"; }
    void addUser() { qDebug() << "test"; }
    void removeUser() { qDebug() << "test"; }
    void editUser() { qDebug() << "test"; }
    void selectMedium() {}
    void selectUser() {}

private:
    Ui::MainWindow *ui;
    Medium *selectedMedium;
    User *selectedUser;
};
#endif // MAINWINDOW_H
