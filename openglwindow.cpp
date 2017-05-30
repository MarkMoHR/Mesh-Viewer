#include "openglwindow.h"
#include <gl/freeglut.h>

#define SCALE_FACTOR 0.1f
#define ROTATE_FACTOR 2.0f
#define TRANSLATE_FACTOR 15.0f
#define LOOKING_DISTANCE_FACTOR 4.0f

GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat LightPosition[] = { 0.0f, 300.0f, 0.0f, 1.0f };    //光照位置
GLfloat LightPosition2[] = { 0.0f, -300.0f, 0.0f, 1.0f };


float int2float(int intensity) {
    return (float)intensity / 255.0f;
}

OpenglWindow::OpenglWindow(QWidget *parent) :QOpenGLWidget(parent)  {
    size = 1.f;
    rotateAngleHoriFi = rotateAngleVertFi = 0;
    rotateAngleHori = rotateAngleVert = 0;
    translateHoriFi = translateVertFi = 0;
    translateHori = translateVert = 0;

    mouseOriPosX = -1;
    mouseOriPosY = -1;

    modelManager = new ModelManager;
}

OpenglWindow::~OpenglWindow() {
    delete modelManager;
}

void OpenglWindow::initializeGL() {
    if (!modelManager->importModel("modelPath.txt"))
        cout << "Import model error!" << endl;

    glEnable(GL_TEXTURE_2D);

    glClearColor(int2float(40), int2float(10), int2float(40), 1.f);
    glClearDepth(1.0f);				// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);		// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);			// The Type Of Depth Test To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculation


    //设置光照
    glEnable(GL_NORMALIZE);    //法向量单位化
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);

    glEnable(GL_LIGHT2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, LightAmbient);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, LightDiffuse);
    glLightfv(GL_LIGHT2, GL_POSITION, LightPosition2);
}

void OpenglWindow::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, (modelManager->scene_max.z - modelManager->scene_min.z) * LOOKING_DISTANCE_FACTOR,
              0, 0, -(modelManager->scene_max.z - modelManager->scene_min.z) * LOOKING_DISTANCE_FACTOR,
              0, 1.0f, 0);

    //放缩
    glScalef(size, size, size);

    //平移
    glTranslatef(translateHoriFi + translateHori, translateVertFi + translateVert, 0);

    //旋转
    glRotatef(rotateAngleHoriFi + rotateAngleHori, 0.f, 1.f, 0.f);
    glRotatef(rotateAngleVertFi + rotateAngleVert, 1.f, 0.f, 0.f);

    //平移：把中心固定为模型中心
    glTranslatef(-(modelManager->scene_center.x),
                 -(modelManager->scene_center.y),
                 -(modelManager->scene_center.z));

    modelManager->renderTheModel();

    //repaint
    update();

}

void OpenglWindow::resizeGL(int width, int height) {
    if (height == 0)
        height = 1;

    glViewport(0, 0, (GLint)width, (GLint)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)width/(GLfloat)height, 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenglWindow::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        mouseOriPosX = event->pos().x();
        mouseOriPosY = event->pos().y();
    }
}

void OpenglWindow::mouseMoveEvent(QMouseEvent *event) {
    int mouseNowPosX = event->pos().x();
    int mouseNowPosY = event->pos().y();
    int dx = mouseNowPosX - mouseOriPosX;    //相对距离
    int dy = mouseNowPosY - mouseOriPosY;

    if (modelManager->transformMode == Rotation) {
        rotateAngleHori = (GLfloat)dx / ROTATE_FACTOR;
        rotateAngleVert = (GLfloat)dy / ROTATE_FACTOR;
    }
    else {
        translateHori = (GLfloat)dx / TRANSLATE_FACTOR;
        translateVert = (GLfloat)-dy / TRANSLATE_FACTOR;
    }
}

void OpenglWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (modelManager->transformMode == Rotation) {
        rotateAngleHoriFi += rotateAngleHori;
        rotateAngleHori = 0;
        rotateAngleVertFi += rotateAngleVert;
        rotateAngleVert = 0;
    }
    else {
        translateHoriFi += translateHori;
        translateHori = 0;
        translateVertFi += translateVert;
        translateVert = 0;
    }
}

void OpenglWindow::wheelEvent(QWheelEvent * event) {
    if (event->delta() > 0) {
        if (size > SCALE_FACTOR)
            size -= SCALE_FACTOR;
    }
    else {
        if (size < SCALE_FACTOR * 30.0f)
            size += SCALE_FACTOR;
    }
}

void OpenglWindow::loadTextureOp() {
    if (modelManager->textureState == TextureOff) {
        if (!modelManager->loadTextures())
            cout << "Load Texture Failure..." << endl;
    }
    modelManager->textureState = TextureOn;
}

void OpenglWindow::deleteTextureOp() {
    modelManager->textureState = TextureOff;
}

void OpenglWindow::showWireframe() {
    modelManager->displayMode = Wireframe;
}

void OpenglWindow::showFlat() {
    modelManager->displayMode = Flat;
}

void OpenglWindow::showFlatlines() {
    modelManager->displayMode = Flatlines;
}

void OpenglWindow::showColorNone() {
    modelManager->displayColor = None;
}

void OpenglWindow::showColorRed() {
    modelManager->displayColor = Red;
}

void OpenglWindow::showColorGreen() {
    modelManager->displayColor = Green;
}

void OpenglWindow::shadingGouraud() {
    modelManager->shadingMode = Gouraud;
}

void OpenglWindow::shadingPhong() {
    modelManager->shadingMode = Phong;
}

void OpenglWindow::shadingFlat() {
    modelManager->shadingMode = FlatS;
}

void OpenglWindow::rotationOp() {
    modelManager->transformMode = Rotation;
}

void OpenglWindow::translationOp() {
    modelManager->transformMode = Translation;
}

void OpenglWindow::subdivisionOn() {
    modelManager->subdivisionDepth = 1;
}

void OpenglWindow::subdivisionOff() {
    modelManager->subdivisionDepth = 0;
}
