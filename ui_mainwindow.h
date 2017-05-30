/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "openglwindow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWireframe;
    QAction *actionFlat;
    QAction *actionFlatlines;
    QAction *actionGouraud_Shading;
    QAction *actionPhong_Shading;
    QAction *actionTextureOn;
    QAction *actionTextureOff;
    QAction *actionColorNone;
    QAction *actionColorRed;
    QAction *actionColorGreen;
    QAction *actionRotate;
    QAction *actionTranslate;
    QAction *actionFlat_Shading;
    QAction *actionSubdivisionOn;
    QAction *actionSubdivisionOff;
    QWidget *centralWidget;
    OpenglWindow *widget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDisplay_Mode;
    QMenu *menuShading_Mode;
    QMenu *menuTexture;
    QMenu *menuColor;
    QMenu *menuTransform;
    QMenu *menuSubdivision;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 600);
        actionWireframe = new QAction(MainWindow);
        actionWireframe->setObjectName(QStringLiteral("actionWireframe"));
        actionFlat = new QAction(MainWindow);
        actionFlat->setObjectName(QStringLiteral("actionFlat"));
        actionFlatlines = new QAction(MainWindow);
        actionFlatlines->setObjectName(QStringLiteral("actionFlatlines"));
        actionGouraud_Shading = new QAction(MainWindow);
        actionGouraud_Shading->setObjectName(QStringLiteral("actionGouraud_Shading"));
        actionPhong_Shading = new QAction(MainWindow);
        actionPhong_Shading->setObjectName(QStringLiteral("actionPhong_Shading"));
        actionTextureOn = new QAction(MainWindow);
        actionTextureOn->setObjectName(QStringLiteral("actionTextureOn"));
        actionTextureOff = new QAction(MainWindow);
        actionTextureOff->setObjectName(QStringLiteral("actionTextureOff"));
        actionColorNone = new QAction(MainWindow);
        actionColorNone->setObjectName(QStringLiteral("actionColorNone"));
        actionColorRed = new QAction(MainWindow);
        actionColorRed->setObjectName(QStringLiteral("actionColorRed"));
        actionColorGreen = new QAction(MainWindow);
        actionColorGreen->setObjectName(QStringLiteral("actionColorGreen"));
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionTranslate = new QAction(MainWindow);
        actionTranslate->setObjectName(QStringLiteral("actionTranslate"));
        actionFlat_Shading = new QAction(MainWindow);
        actionFlat_Shading->setObjectName(QStringLiteral("actionFlat_Shading"));
        actionSubdivisionOn = new QAction(MainWindow);
        actionSubdivisionOn->setObjectName(QStringLiteral("actionSubdivisionOn"));
        actionSubdivisionOff = new QAction(MainWindow);
        actionSubdivisionOff->setObjectName(QStringLiteral("actionSubdivisionOff"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new OpenglWindow(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, -1, 600, 543));
        widget->setFocusPolicy(Qt::ClickFocus);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDisplay_Mode = new QMenu(menuBar);
        menuDisplay_Mode->setObjectName(QStringLiteral("menuDisplay_Mode"));
        menuShading_Mode = new QMenu(menuBar);
        menuShading_Mode->setObjectName(QStringLiteral("menuShading_Mode"));
        menuTexture = new QMenu(menuBar);
        menuTexture->setObjectName(QStringLiteral("menuTexture"));
        menuColor = new QMenu(menuBar);
        menuColor->setObjectName(QStringLiteral("menuColor"));
        menuTransform = new QMenu(menuBar);
        menuTransform->setObjectName(QStringLiteral("menuTransform"));
        menuSubdivision = new QMenu(menuBar);
        menuSubdivision->setObjectName(QStringLiteral("menuSubdivision"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuDisplay_Mode->menuAction());
        menuBar->addAction(menuShading_Mode->menuAction());
        menuBar->addAction(menuTexture->menuAction());
        menuBar->addAction(menuColor->menuAction());
        menuBar->addAction(menuTransform->menuAction());
        menuBar->addAction(menuSubdivision->menuAction());
        menuDisplay_Mode->addAction(actionWireframe);
        menuDisplay_Mode->addAction(actionFlat);
        menuDisplay_Mode->addAction(actionFlatlines);
        menuShading_Mode->addAction(actionGouraud_Shading);
        menuShading_Mode->addAction(actionPhong_Shading);
        menuShading_Mode->addAction(actionFlat_Shading);
        menuTexture->addAction(actionTextureOn);
        menuTexture->addAction(actionTextureOff);
        menuColor->addAction(actionColorNone);
        menuColor->addAction(actionColorRed);
        menuColor->addAction(actionColorGreen);
        menuTransform->addAction(actionRotate);
        menuTransform->addAction(actionTranslate);
        menuSubdivision->addAction(actionSubdivisionOn);
        menuSubdivision->addAction(actionSubdivisionOff);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mesh Viewer", Q_NULLPTR));
        actionWireframe->setText(QApplication::translate("MainWindow", "Wireframe", Q_NULLPTR));
        actionFlat->setText(QApplication::translate("MainWindow", "Flat", Q_NULLPTR));
        actionFlatlines->setText(QApplication::translate("MainWindow", "Flatlines", Q_NULLPTR));
        actionGouraud_Shading->setText(QApplication::translate("MainWindow", "Gouraud Shading", Q_NULLPTR));
        actionPhong_Shading->setText(QApplication::translate("MainWindow", "Phong Shading", Q_NULLPTR));
        actionTextureOn->setText(QApplication::translate("MainWindow", "TextureOn", Q_NULLPTR));
        actionTextureOff->setText(QApplication::translate("MainWindow", "TextureOff", Q_NULLPTR));
        actionColorNone->setText(QApplication::translate("MainWindow", "ColorNone", Q_NULLPTR));
        actionColorRed->setText(QApplication::translate("MainWindow", "ColorRed", Q_NULLPTR));
        actionColorGreen->setText(QApplication::translate("MainWindow", "ColorGreen", Q_NULLPTR));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        actionTranslate->setText(QApplication::translate("MainWindow", "Translate", Q_NULLPTR));
        actionFlat_Shading->setText(QApplication::translate("MainWindow", "Flat Shading", Q_NULLPTR));
        actionSubdivisionOn->setText(QApplication::translate("MainWindow", "SubdivisionOn", Q_NULLPTR));
        actionSubdivisionOff->setText(QApplication::translate("MainWindow", "SubdivisionOff", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuDisplay_Mode->setTitle(QApplication::translate("MainWindow", "Display Mode", Q_NULLPTR));
        menuShading_Mode->setTitle(QApplication::translate("MainWindow", "Shading Mode", Q_NULLPTR));
        menuTexture->setTitle(QApplication::translate("MainWindow", "Texture", Q_NULLPTR));
        menuColor->setTitle(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        menuTransform->setTitle(QApplication::translate("MainWindow", "Transform", Q_NULLPTR));
        menuSubdivision->setTitle(QApplication::translate("MainWindow", "Subdivision", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
