#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QString>
#include <QTextStream>
#include "zonedessin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void doIt(QAction*);
    void delIt(QAction*);
    void geoIt(QAction*);

    void openFile();
    void saveFile();
    void quitApp();
    void displayFile(QString);

private:
    Ui::MainWindow *ui;

    zoneDessin * zoneCentrale;

    QAction * solidAction;
    QAction * dashedAction;
    QAction * dottedAction;

    QAction * blackAction;
    QAction * redAction;
    QAction * blueAction;

    QAction * w1Action;
    QAction * w5Action;
    QAction * w10Action;

    QAction * eraseLastAction;
    QAction * eraseAllAction;

    QAction * strokeAction;
    QAction * rectangleAction;
    QAction * ellipseAction;

    QAction * openAction;
    QAction * saveAction;
    QAction * quitAction;

    QFileDialog * openDialog;
    QFileDialog * saveDialog;
    QMessageBox * msgbox;
};

#endif // MAINWINDOW_H
