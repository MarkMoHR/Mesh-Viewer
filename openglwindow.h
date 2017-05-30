#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>

#include "modelmanager.h"
#include <iostream>
using namespace std;


class OpenglWindow : public QOpenGLWidget {
    Q_OBJECT
public:
    OpenglWindow(QWidget *parent = 0);
    ~OpenglWindow();

public:
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

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);    //点击并移动
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent * event);


private:
    GLfloat size;                 //缩放大小
    GLfloat rotateAngleHoriFi;    //原来旋转角度-水平
    GLfloat rotateAngleVertFi;    //原来旋转角度-垂直
    GLfloat rotateAngleHori;      //鼠标旋转角度-水平
    GLfloat rotateAngleVert;      //鼠标旋转角度-垂直
    GLfloat translateHoriFi;      //原来水平移动距离
    GLfloat translateVertFi;      //原来垂直移动距离
    GLfloat translateHori;        //水平移动距离
    GLfloat translateVert;        //垂直移动距离

    int mouseOriPosX;
    int mouseOriPosY;

    ModelManager* modelManager;

};

#endif // OPENGLWINDOW_H
