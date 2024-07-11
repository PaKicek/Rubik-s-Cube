#include "Window.hpp"
#include <iostream>

int Window::init () {
    if (glfwInit() == false) {
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(screensize[0], screensize[1], "Rubik's Cube", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    const char* filename = "";
    cube.load(filename);
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        return -1;
    }
    glEnable(GL_DEPTH_TEST);
    shaders.resize(7);
    shaders[0] = load_shader("../src/shaders/main.glslv", "../src/shaders/front.glslf");
    shaders[1] = load_shader("../src/shaders/main.glslv", "../src/shaders/left.glslf");
    shaders[2] = load_shader("../src/shaders/main.glslv", "../src/shaders/back.glslf");
    shaders[3] = load_shader("../src/shaders/main.glslv", "../src/shaders/right.glslf");
    shaders[4] = load_shader("../src/shaders/main.glslv", "../src/shaders/bottom.glslf");
    shaders[5] = load_shader("../src/shaders/main.glslv", "../src/shaders/top.glslf");
    shaders[6] = load_shader("../src/shaders/main.glslv", "../src/shaders/inside.glslf");
    Calculatedirection();
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    return 0;
}
void Window::draw () {
    glLoadIdentity();
    glFinish();
    glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 proj = glm::perspective(glm::radians(90.0f), (float)screensize[0] / (float)screensize[1], 0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(cameraposition, cube.getCoordinates(), glm::vec3(0, 1, 0));
    glm::mat4 Matrix = proj * view;
    cube.draw(shaders, Matrix);
    glfwSwapBuffers(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::Calculatedirection () {
    glm::vec3 direction;
    direction.x = rad * sin(angles[0]) * sin(angles[1]);
    direction.y = rad * cos(angles[1]);
    direction.z = rad * cos(angles[0]) * sin(angles[1]);
    cameraposition = direction;
}
void Window::inputproc () {
    if (glfwGetKey(window, GLFW_KEY_W)) {
        Calculatedirection();
        if (angles[1] < -0.1) {
            angles[1] += rotatespeed * 0.01;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_A)) {
        Calculatedirection();
        angles[0] -= rotatespeed * 0.01;
    }
    if (glfwGetKey(window, GLFW_KEY_S)) {
        Calculatedirection();
        if (angles[1] > -3) {
            angles[1] -= rotatespeed * 0.01;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_D)) {
        Calculatedirection();
        angles[0] += rotatespeed * 0.01;
    }
    if (glfwGetKey(window, GLFW_KEY_R)) {
        if (glfwGetKey(window, GLFW_KEY_R) == false) {
            Reset();
        }
    }
    if (glfwGetKey(window, GLFW_KEY_T)) {
        if (glfwGetKey(window, GLFW_KEY_T) == false) {
            Shuffle(0);
        }
    }
    // if (glfwGetKey(window, GLFW_KEY_Y)) {
    //     if (glfwGetKey(window, GLFW_KEY_Y) == false) {
    //         Shuffle(1);
    //     }
    // }
    // if (glfwGetKey(window, GLFW_KEY_U)) {
    //     if (glfwGetKey(window, GLFW_KEY_U) == false) {
    //         Shuffle(2);
    //     }
    // }
    // if (glfwGetKey(window, GLFW_KEY_I)) {
    //     if (glfwGetKey(window, GLFW_KEY_I) == false) {
    //         Shuffle(3);
    //     }
    // }
    if (glfwGetKey(window, GLFW_KEY_ENTER)) {
        if (glfwGetKey(window, GLFW_KEY_ENTER) == false) {
            Solve();
        }
    }
    if (glfwGetKey(window, GLFW_KEY_L)) {
        if (glfwGetKey(window, GLFW_KEY_L) == false) {
            cube.load("input.txt");
        }
    }
    if (glfwGetKey(window, GLFW_KEY_P)) {
        if (glfwGetKey(window, GLFW_KEY_P) == false) {
            cube.write("output.txt");
        }
    }
    if (glfwGetKey(window, GLFW_KEY_UP) && rad > 1.5f) {
        rad -= rad / 100;
        Calculatedirection();
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) && rad < 3.0f) {
        rad += rad / 100;
        Calculatedirection();
    }
    if (glfwGetKey(window, GLFW_KEY_HOME) && rotatespeed < 30) {
        rotatespeed += rotatespeed / 100;
    }
    if (glfwGetKey(window, GLFW_KEY_END) && rotatespeed > 0) {
        rotatespeed -= rotatespeed / 100;
    }
    if (glfwGetKey(window, GLFW_KEY_PAGE_UP) && turnspeed < 100) {
        turnspeed += turnspeed / 100;
    }
    if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) && turnspeed > 0) {
        turnspeed -= turnspeed / 100;
    }
    if (glfwGetKey(window, GLFW_KEY_1)) {
        if (glfwGetKey(window, GLFW_KEY_1) == false) {
            turnHorizontal(0, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_2)) {
        if (glfwGetKey(window, GLFW_KEY_2) == false) {
            turnHorizontal(1, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_3)) {
        if (glfwGetKey(window, GLFW_KEY_3) == false) {
            turnHorizontal(2, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_4)) {
        if (glfwGetKey(window, GLFW_KEY_4) == false) {
            turnVertical(0, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_5)) {
        if (glfwGetKey(window, GLFW_KEY_5) == false) {
            turnVertical(1, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_6)) {
        if (glfwGetKey(window, GLFW_KEY_6) == false) {
            turnVertical(2, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_7)) {
        if (glfwGetKey(window, GLFW_KEY_7) == false) {
            turnLeftRight(0, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_8)) {
        if (glfwGetKey(window, GLFW_KEY_8) == false) {
            turnLeftRight(1, true);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_9)) {
        if (glfwGetKey(window, GLFW_KEY_9) == false) {
            turnLeftRight(2, true);
        }
    }
}
GLFWwindow* Window::getWindow () {
    return window;
}
void Window::rotateCube() {
    for (int i = 0; i < 3; i++) {
        turnHorizontal(i, -1);
    }
}
void Window::turnHorizontal (int row, bool mode) {
    GLfloat currentangle = 0.0f;
    while (currentangle <= 90.0f) {
        currentangle += turnspeed;
        for (int x = 0; x < 3; x++) {
            for (int z = 0; z < 3; z++) {
                if (mode) {
                    cube.parts[x][row][z].model = glm::rotate(cube.parts[x][row][z].model, glm::radians(-turnspeed), glm::vec3(0, -1, 0));
                } else {
                    cube.parts[x][row][z].model = glm::rotate(cube.parts[x][row][z].model, glm::radians(turnspeed), glm::vec3(0, -1, 0));
                }
            }
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            Calculatedirection();
            if (angles[1] < 0) {
                angles[1] += rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_A)) {
            Calculatedirection();
            angles[0] -= rotatespeed * 0.01;
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            Calculatedirection();
            if (angles[1] > -3) {
                angles[1] -= rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            Calculatedirection();
            angles[0] += rotatespeed * 0.01;
        }
        draw();
    }
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[x][row][z].model = glm::mat4(1.0f);
        }
    }
    cube.turnHorizontal(row, mode);
}
void Window::turnVertical (int row, bool mode) {
    GLfloat currentangle = 0.0f;
    while (currentangle <= 80.0f) {
        currentangle += turnspeed;
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (mode) {
                    cube.parts[row][y][z].model = glm::rotate(cube.parts[row][y][z].model, glm::radians(-turnspeed), glm::vec3(-1, 0, 0));
                } else {
                    cube.parts[row][y][z].model = glm::rotate(cube.parts[row][y][z].model, glm::radians(turnspeed), glm::vec3(-1, 0, 0));
                }
            }
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            Calculatedirection();
            if (angles[1] < 0) {
                angles[1] += rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_A)) {
            Calculatedirection();
            angles[0] -= rotatespeed * 0.01;
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            Calculatedirection();
            if (angles[1] > -3) {
                angles[1] -= rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            Calculatedirection();
            angles[0] += rotatespeed * 0.01;
        }
        draw();
    }
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[row][y][z].model = glm::mat4(1.0f);
        }
    }
    cube.turnVertical(row, mode);
}
void Window::turnLeftRight (int row, bool mode) {
    GLfloat currentangle = 0.0f;
    while (currentangle <= 90.0f) {
        currentangle += turnspeed;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (mode) {
                    cube.parts[x][y][row].model = glm::rotate(cube.parts[x][y][row].model, glm::radians(-turnspeed), glm::vec3(0, 0, -1));
                } else {
                    cube.parts[x][y][row].model = glm::rotate(cube.parts[x][y][row].model, glm::radians(turnspeed), glm::vec3(0, 0, -1));
                }
            }
        }
        if (glfwGetKey(window, GLFW_KEY_W)) {
            Calculatedirection();
            if (angles[1] < 0) {
                angles[1] += rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_A)) {
            Calculatedirection();
            angles[0] -= rotatespeed * 0.01;
        }
        if (glfwGetKey(window, GLFW_KEY_S)) {
            Calculatedirection();
            if (angles[1] > -3) {
                angles[1] -= rotatespeed * 0.01;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_D)) {
            Calculatedirection();
            angles[0] += rotatespeed * 0.01;
        }
        draw();
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cube.parts[x][y][row].model = glm::mat4(1.0f);
        }
    }
    cube.turnLeftRight(row, mode);
}
void Window::Reset () {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cube.parts[x][y][0].setSide(0, 0);
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            cube.parts[x][y][2].setSide(2, 2);
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[0][y][z].setSide(1, 1);
        }
    }
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[2][y][z].setSide(3, 3);
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[x][0][z].setSide(4, 4);
        }
    }
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            cube.parts[x][2][z].setSide(5, 5);
        }
    }
}
void Window::Shuffle (int num) {
    // if (num == 1) { //3 6 9 3 6 7 9
    //     turnHorizontal(2, true);
    //     turnVertical(2, true);
    //     turnLeftRight(2, true);
    //     turnHorizontal(2, true);
    //     turnVertical(2, true);
    //     turnLeftRight(0, true);
    //     turnLeftRight(2, true);
    // } else if (num == 2) { //4 7 6 3 2
    //     turnVertical(0, true);
    //     turnLeftRight(0, true);
    //     turnVertical(2, true);
    //     turnHorizontal(2, true);
    //     turnHorizontal(1, true);
    // } else if (num == 3) { //8 6 4 2 9 7 5 3
    //     turnLeftRight(1, true);
    //     turnVertical(2, true);
    //     turnVertical(0, true);
    //     turnHorizontal(1, true);
    //     turnLeftRight(2, true);
    //     turnLeftRight(0, true);
    //     turnVertical(1, true);
    //     turnHorizontal(2, true);
    // } else {
        int countermax = std::rand() % 50;
        int countermin = std::rand() % 20;
        int counter = std::abs(countermax - countermin);
        for (int i = 0; i < counter; i++) {
            int step = std::rand() % 6;
            int row = std::rand() % 3;
            if (step == 1) {
                turnHorizontal(row, true);
            }
            if (step == 2) {
                turnVertical(row, true);
            }
            if (step == 3) {
                turnLeftRight(row, true);
            }
            if (step == 4) {
                turnHorizontal(row, false);
            }
            if (step == 5) {
                turnVertical(row, false);
            }
            if (step == 6) {
                turnLeftRight(row, false);
            }
            draw();
        }
    //}
}
void Window::Solve () {
    FirstCross();
    for (int i = 0; i < 3; i++) {
        turnVertical(i, false);
    }
    for (int i = 0; i < 3; i++) {
        turnVertical(i, false);
    }
    FirstLayer();
    SecondLayer();
    SecondCross();
    for (int i = 0; i < 3; i++) {
        turnLeftRight(i, true);
    }
    ThirdLayer();
    for (int i = 0; i < 3; i++) {
        turnLeftRight(i, false);
    }
    FinalVertices();
    FinalEdges();
}