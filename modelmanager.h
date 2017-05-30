#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include <fstream>
#include <string.h>
#include <map>

#include <gl/freeglut.h>
#include <IL/il.h>

#include <assimp/cimport.h>
#include <assimp/postprocess.h>
#include <assimp/scene.h>


#include <iostream>
using namespace std;

enum TextureState { TextureOn, TextureOff};
enum DisplayColor { None, Green, Red };
enum DisplayMode { Wireframe, Flat, Flatlines };
enum ShadingMode { FlatS, Gouraud, Phong };
enum TransformMode { Rotation, Translation };

class ModelManager {

public:
    ModelManager();
    ~ModelManager();

    bool importModel(const string& pFile);      //加载模型
    bool loadTextures();                        //加载texture
    void renderTheModel();                      //渲染模型入口

public:
    TextureState textureState;     //当前是否已经加载纹理
    DisplayMode displayMode;       //当前显示方式
    DisplayColor displayColor;     //当前颜色
    ShadingMode shadingMode;       //当前shading模式
    TransformMode transformMode;   //当前变换模式
    int subdivisionDepth;          //细分深度，0位不细分

    aiVector3D scene_min, scene_max, scene_center;

private:

    //获取包围盒，得到x/y/z的最大/最小值：用于将模型放置在正中央
    void getBoundingBox();
    void getBoundingBoxRecursive(const struct aiNode* nd, aiMatrix4x4* trafo);

    //递归渲染
    void recursiveRender(const struct aiScene *sc, const struct aiNode* nd);
    void applyMaterial(const aiMaterial *mtl);    //给模型添加texture

    //处理面的函数入口
    void processFace(const struct aiMesh* mesh, GLenum face_mode, const struct aiFace* face);
    void subdivision(aiVector3D vPos1, aiVector3D vPos2, aiVector3D vPos3,
                     aiVector3D vNor1, aiVector3D vNor2, aiVector3D vNor3,
                     aiVector3D vTexPos1, aiVector3D vTexPos2, aiVector3D vTexPos3,
                     int depth);

    //四边形渲染模式
    void renderPolygonFaceFlat(const struct aiMesh* mesh, GLenum face_mode, const struct aiFace* face);
    void renderPolygonFaceWireframe(const struct aiMesh* mesh, const struct aiFace* face);

    //三角形渲染模式
    void renderTriangleFaceFlat(aiVector3D vPos1, aiVector3D vPos2, aiVector3D vPos3,
                                aiVector3D vNor1, aiVector3D vNor2, aiVector3D vNor3,
                                aiVector3D vTexPos1, aiVector3D vTexPos2, aiVector3D vTexPos3);
    void renderTriangleFaceWireframe(aiVector3D vPos1, aiVector3D vPos2, aiVector3D vPos3);
    //三角形渲染phong模式
    void renderFaceFlatPhong(aiVector3D vPos1, aiVector3D vPos2, aiVector3D vPos3,
                                aiVector3D vNor1, aiVector3D vNor2, aiVector3D vNor3,
                                aiVector3D vTexPos1, aiVector3D vTexPos2, aiVector3D vTexPos3);
    void renderSubFaceFlatPhong(aiVector3D vPos1, aiVector3D vPos2, aiVector3D vPos3,
                                aiVector3D vNor1, aiVector3D vNor2, aiVector3D vNor3,
                                aiVector3D vTexPos1, aiVector3D vTexPos2, aiVector3D vTexPos3);

private:
    string modelPath = "";
    const aiScene* scene = NULL;
    GLuint scene_list = 0;

    map<string, GLuint*> textureIdMap;        // map image filenames to textureIds
    GLuint* textureIds = NULL;	        	  // pointer to texture Array
};

#endif // MODELMANAGER_H
