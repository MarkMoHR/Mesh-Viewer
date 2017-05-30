#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionTextureOn, SIGNAL(triggered()), this, SLOT(loadTextureOp()));
    connect(ui->actionTextureOff, SIGNAL(triggered()), this, SLOT(deleteTextureOp()));
    connect(ui->actionColorNone, SIGNAL(triggered()), this, SLOT(showColorNone()));
    connect(ui->actionColorRed, SIGNAL(triggered()), this, SLOT(showColorRed()));
    connect(ui->actionColorGreen, SIGNAL(triggered()), this, SLOT(showColorGreen()));
    connect(ui->actionWireframe, SIGNAL(triggered()), this, SLOT(showWireframe()));
    connect(ui->actionFlat, SIGNAL(triggered()), this, SLOT(showFlat()));
    connect(ui->actionFlatlines, SIGNAL(triggered()), this, SLOT(showFlatlines()));
    connect(ui->actionGouraud_Shading, SIGNAL(triggered()), this, SLOT(shadingGouraud()));
    connect(ui->actionPhong_Shading, SIGNAL(triggered()), this, SLOT(shadingPhong()));
    connect(ui->actionFlat_Shading, SIGNAL(triggered()), this, SLOT(shadingFlat()));
    connect(ui->actionRotate, SIGNAL(triggered()), this, SLOT(rotationOp()));
    connect(ui->actionTranslate, SIGNAL(triggered()), this, SLOT(translationOp()));
    connect(ui->actionSubdivisionOn, SIGNAL(triggered()), this, SLOT(subdivisionOn()));
    connect(ui->actionSubdivisionOff, SIGNAL(triggered()), this, SLOT(subdivisionOff()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadTextureOp() { ui->widget->loadTextureOp(); }
void MainWindow::deleteTextureOp() { ui->widget->deleteTextureOp(); }
void MainWindow::showColorNone() { ui->widget->showColorNone(); }
void MainWindow::showColorRed() { ui->widget->showColorRed(); }
void MainWindow::showColorGreen() { ui->widget->showColorGreen(); }
void MainWindow::showWireframe() { ui->widget->showWireframe(); }
void MainWindow::showFlat() { ui->widget->showFlat(); }
void MainWindow::showFlatlines() { ui->widget->showFlatlines(); }
void MainWindow::shadingGouraud() { ui->widget->shadingGouraud(); }
void MainWindow::shadingPhong() { ui->widget->shadingPhong(); }
void MainWindow::shadingFlat() { ui->widget->shadingFlat(); }
void MainWindow::rotationOp() { ui->widget->rotationOp(); }
void MainWindow::translationOp() { ui->widget->translationOp(); }
void MainWindow::subdivisionOn() { ui->widget->subdivisionOn(); }
void MainWindow::subdivisionOff() { ui->widget->subdivisionOff(); }
