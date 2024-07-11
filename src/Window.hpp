#pragma once
#include "RubikCude.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Window {
    GLFWwindow* window;
    std::vector<Shader*> shaders;
    RubikCube cube;
    int screensize[2] = {720, 720};
    GLfloat rad = 2.0f;
    GLfloat rotatespeed = 10.0f;
    GLfloat turnspeed = 10.0f;
    glm::vec3 cameraposition;
    glm::vec2 angles = glm::vec2(0.75, -1);
    void Calculatedirection();
    void Reset();
    void Shuffle(int num);
    void Solve();
    void rotateCube();
    void turnHorizontal(int row, bool mode);
    void turnVertical(int row, bool mode);
    void turnLeftRight(int row, bool mode);
    bool FirstCrosscheck1();
    bool FirstCrosscheck2();
    bool FirstLayercheck();
    bool SecondLayercheck();
    bool ThirdLayercheck();
    bool FinalVerticescheck();
    bool FinalEdgescheck();
    void PifPaf1();
    void PifPaf2();
    void PifPaf3();
    void FirstCross();
    void FirstLayer();
    void SecondLayer();
    void SecondCross();
    void ThirdLayer();
    void FinalVertices();
    void FinalEdges();
public:
    int init();
    void inputproc();
    void draw();
    GLFWwindow* getWindow();
    void turnSide();
};