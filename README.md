# Mesh-Viewer
An OpenGL mesh viewer with a GUI menu of functionalities implemented with Qt.

1  Functionalities
--------------------------------------
- Read in many types of mesh model, such as .obj, .x, .dae, and then display the model
- 3 display mode: Flatlines, Wireframe, Flat
- 3 shading mode: Flat Shading, Gouraud Shading and Phong Shading
- Texture mapping/remove
- Color overlay
- 3 transform: Translation, Rotation and Scale
- Mid point subdivision
- A menu bar that contain the buttons of above functions.

2  Coding Environment & 3rd Party Library
--------------------------------------------
- C++
- freeglut
- Qt5.8.0(for Windows 32-bit, VS2015)
- Assimp (For importing mesh model)   http://assimp.sourceforge.net/
- IL (For processing image data)


3  Effect screenshots
--------------------------------------------
- 3 display mode: Flatlines, Wireframe, Flat

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/display.png)

- 3 transform: Translation, Rotation and Scale

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/transform.png)

- Texture mapping

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/textureOn.png)

- Color overlay

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/color.png)

- 3 shading mode: Flat Shading, Gouraud Shading and Phong Shading

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/shading.png)

- Read in different types of mesh model:

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/models.png)

- Mid point subdivision

![Image text](https://github.com/MarkMoHR/Mesh-Viewer/raw/master/EffectScreenshots/subdivision.png)


4  Executable program
--------------------------------------------
Find the _MeshViewer.exe_ at "/Executable program" and run it! Then choose the functions at the menu bar.

See _modelPath.txt_ at "/Executable program", and choose your favorite model :)
