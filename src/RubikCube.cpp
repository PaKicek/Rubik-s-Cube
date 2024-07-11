#include "RubikCude.hpp"
#include <iostream>

void RubikCube::draw (std::vector<Shader*> shaders, glm::mat4 Matrix) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                parts[x][y][z].draw(shaders, Matrix);
            }
        }
    }
}
void RubikCube::load (const char* filename) {
    size = 1;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                parts[x][y][z].setX((x - 1) * (size / 3));
                parts[x][y][z].setY((y - 1) * (size / 3));
                parts[x][y][z].setZ((z - 1) * (size / 3));
                parts[x][y][z].load(size);
            }
        }
    }
    if (strcmp(filename, "")) {
        FILE* file = fopen("io.txt", "rb");
        if (file) {
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    for (int z = 0; z < 3; z++) {
                        for (int i = 0; i < 6; i++) {
                            if (feof(file) == false) {
                                int currentside = getc(file);
                                //std::cout << currentside << " ";
                                if (currentside == 0) {
                                    parts[x][y][z].setSide(i, 0);
                                }
                                if (currentside == 1) {
                                    parts[x][y][z].setSide(i, 1);
                                }
                                if (currentside == 2) {
                                    parts[x][y][z].setSide(i, 2);
                                }
                                if (currentside == 3) {
                                    parts[x][y][z].setSide(i, 3);
                                }
                                if (currentside == 4) {
                                    parts[x][y][z].setSide(i, 4);
                                }
                                if (currentside == 5) {
                                    parts[x][y][z].setSide(i, 5);
                                }
                            } else {
                                std::cout << "File io.txt does not match required format\n";
                                return;
                            }
                        }
                    }
                }
            }
            std::cout << "Successfully read data from file io.txt\n";
        } else {
            std::cout << "File io.txt does not exist\n";
            return;
        }
        fclose(file);
    }
}
void RubikCube::write (const char* filename) {
    FILE* file = fopen("io.txt", "wb");
    if (file) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    for (int i = 0; i < 6; i++) {
                        int currentside = parts[x][y][z].getSide(i);
                        putc(currentside, file);
                    }
                }
            }
        }
        std::cout << "Successfully written data to file io.txt\n";
    }
    fclose(file);
}
void RubikCube::turnHorizontal (int row, bool mode = 0) {
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            if (mode) {
                parts[x][row][z].turnLeft();
            } else {
                parts[x][row][z].turnRight();
            }
        }
    }
    CubePart first = parts[0][row][0];
    CubePart second = parts[0][row][2];
    CubePart third = parts[2][row][2];
    CubePart fourth = parts[2][row][0];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[0][row][2].setSide(i, first.getSide(i));
            parts[2][row][2].setSide(i, second.getSide(i));
            parts[2][row][0].setSide(i, third.getSide(i));
            parts[0][row][0].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[2][row][0].setSide(i, first.getSide(i));
            parts[0][row][0].setSide(i, second.getSide(i));
            parts[0][row][2].setSide(i, third.getSide(i));
            parts[2][row][2].setSide(i, fourth.getSide(i));
        }
    }
    first = parts[1][row][0];
    second = parts[0][row][1];
    third = parts[1][row][2];
    fourth = parts[2][row][1];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[0][row][1].setSide(i, first.getSide(i));
            parts[1][row][2].setSide(i, second.getSide(i));
            parts[2][row][1].setSide(i, third.getSide(i));
            parts[1][row][0].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[2][row][1].setSide(i, first.getSide(i));
            parts[1][row][0].setSide(i, second.getSide(i));
            parts[0][row][1].setSide(i, third.getSide(i));
            parts[1][row][2].setSide(i, fourth.getSide(i));
        }
    }
}
void RubikCube::turnVertical (int row, bool mode = 0) {
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            if (mode) {
                parts[row][y][z].turnForward();
            } else {
                parts[row][y][z].turnBackward();
            }
        }
    }
    CubePart first = parts[row][0][0];
    CubePart second = parts[row][0][2];
    CubePart third = parts[row][2][2];
    CubePart fourth = parts[row][2][0];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[row][2][0].setSide(i, first.getSide(i));
            parts[row][0][0].setSide(i, second.getSide(i));
            parts[row][0][2].setSide(i, third.getSide(i));
            parts[row][2][2].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[row][0][2].setSide(i, first.getSide(i));
            parts[row][2][2].setSide(i, second.getSide(i));
            parts[row][2][0].setSide(i, third.getSide(i));
            parts[row][0][0].setSide(i, fourth.getSide(i));
        }
    }
    first = parts[row][1][0];
    second = parts[row][0][1];
    third = parts[row][1][2];
    fourth = parts[row][2][1];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[row][2][1].setSide(i, first.getSide(i));
            parts[row][1][0].setSide(i, second.getSide(i));
            parts[row][0][1].setSide(i, third.getSide(i));
            parts[row][1][2].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[row][0][1].setSide(i, first.getSide(i));
            parts[row][1][2].setSide(i, second.getSide(i));
            parts[row][2][1].setSide(i, third.getSide(i));
            parts[row][1][0].setSide(i, fourth.getSide(i));
        }
    }
}
void RubikCube::turnLeftRight (int row, bool mode = 0) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            parts[x][y][row].turnForward();
            if (mode) {
                parts[x][y][row].turnRight();
            } else {
                parts[x][y][row].turnLeft();
            }
            parts[x][y][row].turnBackward();
        }
    }
    CubePart first = parts[0][0][row];
    CubePart second = parts[2][0][row];
    CubePart third = parts[2][2][row];
    CubePart fourth = parts[0][2][row];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[2][0][row].setSide(i, first.getSide(i));
            parts[2][2][row].setSide(i, second.getSide(i));
            parts[0][2][row].setSide(i, third.getSide(i));
            parts[0][0][row].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[0][2][row].setSide(i, first.getSide(i));
            parts[0][0][row].setSide(i, second.getSide(i));
            parts[2][0][row].setSide(i, third.getSide(i));
            parts[2][2][row].setSide(i, fourth.getSide(i));
        }
    }
    first = parts[0][1][row];
    second = parts[1][2][row];
    third = parts[2][1][row];
    fourth = parts[1][0][row];
    if (mode) {
        for (int i = 0; i < 6; i++) {
            parts[1][0][row].setSide(i, first.getSide(i));
            parts[0][1][row].setSide(i, second.getSide(i));
            parts[1][2][row].setSide(i, third.getSide(i));
            parts[2][1][row].setSide(i, fourth.getSide(i));
        }
    } else {
        for (int i = 0; i < 6; i++) {
            parts[1][2][row].setSide(i, first.getSide(i));
            parts[2][1][row].setSide(i, second.getSide(i));
            parts[1][0][row].setSide(i, third.getSide(i));
            parts[0][1][row].setSide(i, fourth.getSide(i));
        }
    }
}

glm::vec3 RubikCube::getCoordinates () {
    return coordinates;
}