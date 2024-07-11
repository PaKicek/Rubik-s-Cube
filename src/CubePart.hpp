#pragma once
#include "Shader.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class CubePart {
    glm::vec3 coords;
    int sides[6] = {0, 1, 2, 3, 4, 5};
    float vertices[8][3];
public:
    glm::mat4 model = glm::mat4(1.0f);
    void load(float size);
    void draw(std::vector<Shader*> shaders, glm::mat4 Matrix);
    float getX();
    float getY();
    float getZ();
    int getSide(int index);
    void setX(float value);
    void setY(float value);
    void setZ(float value);
    void setSide(int index, int num);
    void turnLeft();
    void turnRight();
    void turnForward();
    void turnBackward();
};