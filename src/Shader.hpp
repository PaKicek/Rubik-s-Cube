#pragma once
#include <string>
#include <vector>

class Shader {
public:
    int id;
    Shader(int id);
    void use();
    ~Shader();
};
extern Shader* load_shader(std::string VertexFile, std::string FragFile);