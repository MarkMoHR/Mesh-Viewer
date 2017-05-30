#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private slots:
        void loadTextureOp();        //加载纹理
        void deleteTextureOp();      //删除纹理
        void showColorNone();        //显示颜色
        void showColorRed();
        void showColorGreen();
        void showWireframe();        //三种显示方式
        void showFlat();
        void showFlatlines();
        void shadingGouraud();       //三种shading方式
        void shadingPhong();
        void shadingFlat();
        void rotationOp();           //两种变换方式
        void translationOp();
        void subdivisionOn();        //是否做细分
        void subdivisionOff();

    private:
        Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
