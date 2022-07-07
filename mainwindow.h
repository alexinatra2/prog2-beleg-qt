#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
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
    void on_addUserButton_released();
    void on_addMediumButton_released();
    void on_borrowMediumButton_released();
    void addUser(User *user);
    void removeUser();

private:
    Ui::MainWindow *ui;
    Medium *selectedMedium;
    User *selectedUser;
};
#endif // MAINWINDOW_H
