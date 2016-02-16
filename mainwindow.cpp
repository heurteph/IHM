#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zonedessin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    // Attributs graphiques

    statusBar();

    QMenuBar * myMenuBar = menuBar();
    QMenu * fileMenu     = myMenuBar->addMenu(tr("&Fichier"));
    QMenu * styleMenu    = myMenuBar->addMenu(tr("&Style"));
    QMenu * colorMenu    = myMenuBar->addMenu(tr("&Color"));
    QMenu * widthMenu    = myMenuBar->addMenu(tr("&Width"));
    QMenu * deleteMenu   = myMenuBar->addMenu(tr("&Delete"));
    QMenu * geometryMenu = myMenuBar->addMenu(tr("&Geometry"));

    QActionGroup *group         = new QActionGroup(this);
    QActionGroup *groupDelete   = new QActionGroup(this);
    QActionGroup *groupGeometry = new QActionGroup(this);


    // Panneau Central

    zoneCentrale = new zoneDessin();
    setCentralWidget(zoneCentrale);

    // Connexions

    connect(group,SIGNAL(triggered(QAction*)),this,SLOT(doIt(QAction*)));
    connect(groupDelete,SIGNAL(triggered(QAction*)),this,SLOT(delIt(QAction*)));
    connect(groupGeometry,SIGNAL(triggered(QAction*)),this,SLOT(geoIt(QAction*)));

    // Actions

    solidAction  = group->addAction(tr("Solid")); //new QAction(tr("Solid"), this);
    dashedAction = group->addAction(tr("Dashed")); //new QAction(tr("Dashed"), this);
    dottedAction = group->addAction(tr("Dotted")); //new QAction(tr("Dotted"), this);

    blackAction  = group->addAction(tr("Black"));
    redAction    = group->addAction(tr("Red"));
    blueAction   = group->addAction(tr("Blue"));

    w1Action  = group->addAction(tr("1px"));
    w5Action  = group->addAction(tr("5px"));
    w10Action = group->addAction(tr("10px"));

    eraseLastAction = groupDelete->addAction(tr("Erase last"));
    eraseAllAction  = groupDelete->addAction(tr("Erase all"));

    strokeAction     = groupGeometry->addAction(tr("Stroke"));
    rectangleAction  = groupGeometry->addAction(tr("Rectangle"));
    ellipseAction    = groupGeometry->addAction(tr("Ellipse"));

    openAction = new QAction(QIcon(":/myPrefix/icons/images/open.png"), tr("&Ouvrir"), this);
    saveAction = new QAction(QIcon(":/myPrefix/icons/images/save.png"), tr("&Sauvegarder"), this);
    quitAction = new QAction(QIcon(":/myPrefix/icons/images/quit.png"), tr("&Quitter"), this);


    // Menus

    styleMenu->addAction(solidAction);
    styleMenu->addAction(dashedAction);
    styleMenu->addAction(dottedAction);

    colorMenu->addAction(blackAction);
    colorMenu->addAction(redAction);
    colorMenu->addAction(blueAction);

    widthMenu->addAction(w1Action);
    widthMenu->addAction(w5Action);
    widthMenu->addAction(w10Action);

    deleteMenu->addAction(eraseLastAction);
    deleteMenu->addAction(eraseAllAction);

    geometryMenu->addAction(strokeAction);
    geometryMenu->addAction(rectangleAction);
    geometryMenu->addAction(ellipseAction);

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(quitAction);


    //Sauvegarde et lecture

    //statusBar();
    QToolBar * fileToolBar = addToolBar(tr("&Fichier"));
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);
    fileToolBar->addAction(quitAction);

    openDialog = new QFileDialog();
    saveDialog = new QFileDialog();

    connect(openAction,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(quitApp()));

    connect(openDialog,SIGNAL(fileSelected(QString)),this,SLOT(displayFile(QString)));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::doIt(QAction* sender){

    if(sender == solidAction){
        zoneCentrale->setPenStyle(Qt::SolidLine);
    }
    else if(sender == dashedAction){
        zoneCentrale->setPenStyle(Qt::DashLine);
    }
    else if(sender == dottedAction){
        zoneCentrale->setPenStyle(Qt::DotLine);
    }
    else if(sender == blackAction){
        zoneCentrale->setPenColor(QColor("black"));
    }
    else if(sender == blueAction){
        zoneCentrale->setPenColor(QColor("blue"));
    }
    else if(sender == redAction){
        zoneCentrale->setPenColor(QColor("red"));
    }
    else if(sender == w1Action){
        zoneCentrale->setPenWidth(1);
    }
    else if(sender == w5Action){
        zoneCentrale->setPenWidth(5);
    }
    else if(sender == w10Action){
        zoneCentrale->setPenWidth(10);
    }
}


void MainWindow::delIt(QAction* sender){

    if(sender == eraseLastAction){
        zoneCentrale->eraseLast();
    }
    else if(sender == eraseAllAction){
        zoneCentrale->eraseAll();
    }
}

void MainWindow::geoIt(QAction* sender){

    if(sender == strokeAction){
        zoneCentrale->setForm(t_Stroke);
    }
    else if(sender == rectangleAction){
        zoneCentrale->setForm(t_Rectangle);
    }
    else if(sender == ellipseAction){
        zoneCentrale->setForm(t_Ellipse);
    }
}

/* Sauvegarde et lecture */

void MainWindow::openFile(){
    std::cout << "J'ouvre un fichier" << std::endl;
    openDialog->show();
}

void MainWindow::saveFile(){
    std::cout << "Je sauvegarde un fichier" << std::endl;
    QString fileName = QFileDialog::getSaveFileName( this, tr("Save Text"), "/cal/exterieurs/ext7761/MonProjet/save/", tr ("Text Files (*.txt)") );
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream stream(&file);
    }
}

void MainWindow::quitApp(){
    QMessageBox msgbox;
    msgbox.setText("L'application va se fermer");
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int ret = msgbox.exec();
    if(ret == QMessageBox::Yes){
        qApp->exit();
    }
    else{
        //std::cout << "Je ferme l'application" << std::endl;
    }
}

void MainWindow::displayFile(QString string){
    std::cout << qPrintable(string) << std::endl;
    QFile file(string);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream stream(&file);
        QString text = stream.readAll();
    }
}
