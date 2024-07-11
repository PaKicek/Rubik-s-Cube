#include "CubePart.hpp"

void CubePart::draw (std::vector<Shader*> shaders, glm::mat4 Matrix) {
    std::vector<float> VertexData;
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[3][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[0][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[3][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[0][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[4][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[0][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[3][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[4][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[5][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[5][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[7][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[7][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[5][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[7][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[0][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[1][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[5][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[0][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[4][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[5][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[3][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[7][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[2][i]);
    }
    for (int i = 0; i < 3; i++) {
        VertexData.push_back(vertices[6][i]);
    }
    GLuint VertexArray;
    glGenVertexArrays(1, &VertexArray);
    glBindVertexArray(VertexArray);
    GLfloat VertexBufferData[108];
    for (int i = 0; i < 108; i++) {
        VertexBufferData[i] = VertexData[i];
    }
    VertexData.clear();
    GLuint VertexBuffer;
    glGenBuffers(1, &VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(VertexBufferData), VertexBufferData, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    Matrix = Matrix * model;
    for (int i = 0; i < 6; i++) {
        shaders[getSide(i)]->use();
        GLint MatrixIdentifier = glGetUniformLocation(shaders[getSide(i)]->id, "Matrix");
        glUniformMatrix4fv(MatrixIdentifier, 1, GL_FALSE, &Matrix[0][0]);
        glDrawArrays(GL_TRIANGLES, 6 * i, 6);
    }
    glBufferSubData(VertexBuffer, 0, 3, (void*)0);
    glDeleteVertexArrays(1, &VertexArray);
    glDeleteBuffers(1, &VertexBuffer);
    glDeleteVertexArrays(1, &VertexBuffer);
    glDeleteBuffers(1, &VertexArray);
}
void CubePart::load (float size) {
    if (getX() != size / 3) {
        setSide(3, 6);
    }
    if (getX() != -size / 3) {
        setSide(1, 6);
    }
    if (getY() != size / 3) {
        setSide(5, 6);
    }
    if (getY() != -size / 3) {
        setSide(4, 6);
    }
    if (getZ() != size / 3) {
        setSide(2, 6);
    }
    if (getZ() != -size / 3) {
        setSide(0, 6);
    }
    vertices[0][0] = getX() - (0.17 * size);
    vertices[0][1] = getY() - (0.17 * size);
    vertices[0][2] = getZ() - (0.17 * size);
    vertices[1][0] = getX() + (0.17 * size);
    vertices[1][1] = getY() - (0.17 * size);
    vertices[1][2] = getZ() - (0.17 * size);
    vertices[2][0] = getX() + (0.17 * size);
    vertices[2][1] = getY() + (0.17 * size);
    vertices[2][2] = getZ() - (0.17 * size);
    vertices[3][0] = getX() - (0.17 * size);
    vertices[3][1] = getY() + (0.17 * size);
    vertices[3][2] = getZ() - (0.17 * size);
    vertices[4][0] = getX() - (0.17 * size);
    vertices[4][1] = getY() - (0.17 * size);
    vertices[4][2] = getZ() + (0.17 * size);
    vertices[5][0] = getX() + (0.17 * size);
    vertices[5][1] = getY() - (0.17 * size);
    vertices[5][2] = getZ() + (0.17 * size);
    vertices[6][0] = getX() - (0.17 * size);
    vertices[6][1] = getY() + (0.17 * size);
    vertices[6][2] = getZ() + (0.17 * size);
    vertices[7][0] = getX() + (0.17 * size);
    vertices[7][1] = getY() + (0.17 * size);
    vertices[7][2] = getZ() + (0.17 * size);
}
void CubePart::turnLeft () {
    int newsides[6];
    newsides[0] = sides[3];
    newsides[1] = sides[0];
    newsides[2] = sides[1];
    newsides[3] = sides[2];
    newsides[4] = sides[4];
    newsides[5] = sides[5];
    for (int i = 0; i < 6; i++) {
        sides[i] = newsides[i];
    }
}
void CubePart::turnRight () {
    int newsides[6];
    newsides[0] = sides[1];
    newsides[1] = sides[2];
    newsides[2] = sides[3];
    newsides[3] = sides[0];
    newsides[4] = sides[4];
    newsides[5] = sides[5];
    for (int i = 0; i < 6; i++) {
        sides[i] = newsides[i];
    }
}
void CubePart::turnForward () {
    int newsides[6];
    newsides[0] = sides[4];
    newsides[1] = sides[1];
    newsides[2] = sides[5];
    newsides[3] = sides[3];
    newsides[4] = sides[2];
    newsides[5] = sides[0];
    for (int i = 0; i < 6; i++) {
        sides[i] = newsides[i];
    }
}
void CubePart::turnBackward () {
    int newsides[6];
    newsides[0] = sides[5];
    newsides[1] = sides[1];
    newsides[2] = sides[4];
    newsides[3] = sides[3];
    newsides[4] = sides[0];
    newsides[5] = sides[2];
    for (int i = 0; i < 6; i++) {
        sides[i] = newsides[i];
    }
}
float CubePart::getX () {
    return coords.x;
}
float CubePart::getY () {
    return coords.y;
}
float CubePart::getZ () {
    return coords.z;
}
int CubePart::getSide (int index) {
    return sides[index];
}
void CubePart::setX (float value) {
    coords.x = value;
}
void CubePart::setY (float value) {
    coords.y = value;
}
void CubePart::setZ (float value) {
    coords.z = value;
}
void CubePart::setSide (int index, int value) {
    sides[index] = value;
}