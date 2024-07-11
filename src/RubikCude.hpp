#pragma once
#include "CubePart.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <fstream>
#include <cstring>

class RubikCube {
    float size;
    glm::vec3 coordinates = glm::vec3(0.0f, 0.0f, 0.0f);
public:
    CubePart parts[3][3][3];
    void load(const char* filename);
    void write(const char* filename);
    void draw(std::vector<Shader*> shaders, glm::mat4 Matrix);
    void turnHorizontal(int row, bool mode);
    void turnVertical(int row, bool mode);
    void turnLeftRight(int row, bool mode);
    glm::vec3 getCoordinates();
};