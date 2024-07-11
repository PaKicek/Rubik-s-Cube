#include "Window.hpp"
#include <iostream>

bool Window::FirstCrosscheck1 () {
    int counter = 0;
    cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[1][2][0].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[1][2][2].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[2][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    if (counter == 4) {
        return true;
    } else {
        return false;
    }
}
bool Window::FirstCrosscheck2 () {
    int counter = 0;
    cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[1][2][0].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[1][2][2].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[2][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) ? counter++ : counter;
    cube.parts[0][2][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[1][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[1][2][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    cube.parts[2][2][1].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    if (counter == 8) {
        return true;
    } else {
        return false;
    }
}
bool Window::FirstLayercheck () {
    int counter = 0;
    cube.parts[0][0][0].getSide(4) == cube.parts[1][0][1].getSide(4) ? counter++ : counter;
    cube.parts[0][0][2].getSide(4) == cube.parts[1][0][1].getSide(4) ? counter++ : counter;
    cube.parts[2][0][0].getSide(4) == cube.parts[1][0][1].getSide(4) ? counter++ : counter;
    cube.parts[2][0][2].getSide(4) == cube.parts[1][0][1].getSide(4) ? counter++ : counter;
    if (counter == 4) {
        return true;
    } else {
        return false;
    }
}
bool Window::SecondLayercheck () {
    int counter = 0;
    cube.parts[0][1][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[2][1][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[0][1][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    cube.parts[2][1][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    cube.parts[0][1][0].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[2][1][0].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    cube.parts[0][1][2].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[2][1][2].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    if (counter == 8) {
        return true;
    } else {
        return false;
    }
}
bool Window::ThirdLayercheck () {
    int counter = 0;
    cube.parts[0][0][0].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][0][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][0][2].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][1][0].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][1][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][1][2].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][2][0].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][2][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][2][2].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    if (counter == 9) {
        return true;
    } else {
        return false;
    }
}
bool Window::FinalVerticescheck () {
    int counter = 0;
    cube.parts[0][2][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[1][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[1][2][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    cube.parts[2][2][1].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    if (counter == 4) {
        return true;
    } else {
        return false;
    }
}
bool Window::FinalEdgescheck () {
    int counter = 0;
    cube.parts[0][2][0].getSide(4) == cube.parts[1][2][1].getSide(4) ? counter++ : counter;
    cube.parts[0][2][2].getSide(4) == cube.parts[1][2][1].getSide(4) ? counter++ : counter;
    cube.parts[2][2][0].getSide(4) == cube.parts[1][2][1].getSide(4) ? counter++ : counter;
    cube.parts[2][2][2].getSide(4) == cube.parts[1][2][1].getSide(4) ? counter++ : counter;
    cube.parts[0][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[0][2][0].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][2][2].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
    cube.parts[0][2][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    cube.parts[2][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
    cube.parts[2][2][0].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    cube.parts[2][2][2].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
    cube.parts[2][2][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
    if (counter == 12) {
        return true;
    } else {
        return false;
    }
}
void Window::PifPaf1 () {
    turnVertical(2, true);
    turnHorizontal(2, true);
    turnVertical(2, false);
    turnHorizontal(2, false);
}
void Window::PifPaf2 () {
    turnVertical(2, false);
    turnHorizontal(2, true);
    turnHorizontal(2, true);
    turnVertical(2, true);
    turnHorizontal(2, true);
    turnHorizontal(2, true);
    turnVertical(2, false);
}
void Window::PifPaf3 () {
    turnVertical(0, true);
    turnHorizontal(2, false);
    turnVertical(0, false);
    turnHorizontal(2, true);
}
void Window::FirstCross () {
    int counter = 0;
    while (FirstCrosscheck1() == false) {
        if (counter > 50) {
            std::cout << "Solution has cycled: shuffling and resolving\n";
            Shuffle(0);
            counter = 0;
        } else {
            counter++;
        }
        if (cube.parts[1][0][0].getSide(4) == cube.parts[1][2][1].getSide(5)) {
            turnHorizontal(2, true);
            turnLeftRight(0, true);
        }
        if (cube.parts[0][1][0].getSide(0) == cube.parts[1][2][1].getSide(5)) {
            if (cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5)) {
                turnHorizontal(2, true);
                turnVertical(0, true);
                turnHorizontal(2, false);
            } else {
                turnVertical(0, true);
            }
        }
        if (cube.parts[2][1][0].getSide(0) == cube.parts[1][2][1].getSide(5)) {
            if (cube.parts[2][2][1].getSide(5) == cube.parts[1][2][1].getSide(5)) {
                turnHorizontal(2, false);
                turnVertical(2, true);
                turnHorizontal(2, true);
            } else {
                turnVertical(2, true);
            }
        }
        if (cube.parts[1][2][0].getSide(0) == cube.parts[1][2][1].getSide(5)) {
            if (cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5)) {
                turnLeftRight(0, true);
                turnVertical(0, true);
            } else {
                turnLeftRight(0, false);
                turnVertical(2, true);
            }
        }
        if (cube.parts[1][0][0].getSide(0) == cube.parts[1][2][1].getSide(5)) {
            if (cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5)) {
                turnLeftRight(0, true);
                turnVertical(2, true);
            } else {
                turnLeftRight(0, false);
                turnVertical(0, true);
            }
        }
        rotateCube();
        // if (counter < 5) {
        //     rotateCube();
        //     counter++;
        // } else {
        //     std::cout << "Solution has cycled: shuffling and resolving\n";
        //     counter = 0;
        //     Shuffle();
        //     Solve();
        //     return;
        // }
    }
    counter = 0;
    while (FirstCrosscheck2() == false) {
        if (counter > 10) {
            std::cout << "Solution has cycled: shuffling and resolving\n";
            Shuffle(0);
            FirstCross();
            return;
            counter = 0;
        } else {
            counter++;
        }
        if (cube.parts[2][2][1].getSide(3) == cube.parts[1][1][2].getSide(2) && cube.parts[1][2][2].getSide(2) == cube.parts[2][1][1].getSide(3)) {
            PifPaf1();
            turnVertical(2, true);
        } else if (cube.parts[0][2][1].getSide(1) == cube.parts[2][1][1].getSide(3) || cube.parts[2][2][1].getSide(3) == cube.parts[0][1][1].getSide(1)) {
            PifPaf2();
        }
        turnHorizontal(0, true);
        turnHorizontal(1, true);
        turnHorizontal(2, true);
    }
    std::cout << "Solved First Cross\n";
}
void Window::FirstLayer () {
    int counter = 0;
    while (FirstLayercheck() == false) {
        if (counter > 50) {
            std::cout << "Solution has cycled: shuffling and resolving\n";
            turnLeftRight(1, false);
            turnHorizontal(3, false);
            turnVertical(1, false);
            turnHorizontal(3, false);
            turnLeftRight(1, false);
            //Shuffle();
            FirstCross();
            FirstLayer();
            return;
            counter = 0;
        } else {
            counter++;
        }
        for (int i = 0; i < 11; i++) {
            if (cube.parts[2][2][0].getSide(0) == cube.parts[1][0][1].getSide(4) && cube.parts[2][2][0].getSide(5) == cube.parts[1][1][0].getSide(0) && cube.parts[2][2][0].getSide(3) == cube.parts[2][1][1].getSide(3)) {
                PifPaf1();
                PifPaf1();
                PifPaf1();
                PifPaf1();
                PifPaf1();
            } else if (cube.parts[2][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) && cube.parts[2][2][0].getSide(5) == cube.parts[2][1][1].getSide(3) && cube.parts[2][2][0].getSide(3) == cube.parts[1][0][1].getSide(4)) {
                PifPaf1();
            } else if (cube.parts[2][2][0].getSide(0) == cube.parts[2][1][1].getSide(3) && cube.parts[2][2][0].getSide(5) == cube.parts[1][0][1].getSide(4) && cube.parts[2][2][0].getSide(3) == cube.parts[1][1][0].getSide(0)) {
                PifPaf1();
                PifPaf1();
                PifPaf1();
            } else if (cube.parts[2][0][0].getSide(0) != cube.parts[1][1][0].getSide(0) || cube.parts[2][0][0].getSide(3) != cube.parts[2][1][1].getSide(3) && cube.parts[2][0][0].getSide(4) != cube.parts[1][0][1].getSide(4)) {
                PifPaf1();
            }
            if (i < 6) {
                turnHorizontal(2, true);
            } else {
                rotateCube();
                // if (counter < 5) {
                //     rotateCube();
                //     counter++;
                // } else {
                //     std::cout << "Solution has cycled: shuffling and resolving\n";
                //     counter = 0;
                //     Shuffle();
                //     Solve();
                //     return;
                // }
            }
        }
    }
    counter = 0;
    while (cube.parts[1][1][0].getSide(0) != 0) {
        if (counter > 10) {
            std::cout << "Solution has cycled: shuffling and resolving\n";
            turnLeftRight(1, true);
            turnVertical(2, true);
            turnHorizontal(1, true);
            Shuffle(0);
            Shuffle(0);
            Shuffle(0);
            FirstCross();
            FirstLayer();
            return;
            counter = 0;
        } else {
            counter++;
        }
        rotateCube();
        // if (counter < 5) {
        //     rotateCube();
        //     counter++;
        // } else {
        //     std::cout << "Solution has cycled: shuffling and resolving\n";
        //     counter = 0;
        //     Shuffle();
        //     Solve();
        //     return;
        // }
    }
    std::cout << "Solved First Layer\n";
}
void Window::SecondLayer () {
    int counter = 0;
    while (SecondLayercheck() == false) {
        if (counter > 10) {
            std::cout << "Solution has cycled: shuffling and resolving\n";
            Shuffle(0);
            Shuffle(0);
            Shuffle(0);
            FirstCross();
            FirstLayer();
            SecondLayer();
            return;
            counter = 0;
        } else {
            counter++;
        }
        for (int i = 0; i < 11; i++) {
            if (cube.parts[1][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) && cube.parts[1][2][0].getSide(5) == cube.parts[0][1][1].getSide(1)) {
                turnHorizontal(2, false);
                PifPaf3();
                turnHorizontal(2, false);
                turnHorizontal(1, false);
                turnHorizontal(0, false);
                PifPaf1();
            } else if (cube.parts[1][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) && cube.parts[1][2][0].getSide(5) == cube.parts[2][1][1].getSide(3)) {
                turnHorizontal(2, true);
                PifPaf1();
                turnHorizontal(2, true);
                turnHorizontal(1, true);
                turnHorizontal(0, true);
                PifPaf3();
            } else if (cube.parts[2][1][0].getSide(3) != cube.parts[2][1][1].getSide(3) && cube.parts[2][1][0].getSide(0) != cube.parts[1][1][0].getSide(0)) {
                PifPaf1();
                turnHorizontal(2, true);
                turnHorizontal(1, true);
                turnHorizontal(0, true);
                PifPaf3();
            }
            if (i < 6) {
                turnHorizontal(2, true);
            } else {
                rotateCube();
                // if (counter < 5) {
                //     rotateCube();
                //     counter++;
                // } else {
                //     std::cout << "Solution has cycled: shuffling and resolving\n";
                //     counter = 0;
                //     Shuffle();
                //     Solve();
                //     return;
                // }
            }
        }
    }
    std::cout << "Solved Second Layer\n";
}
void Window::SecondCross () {
    for (int i = 0; i < 16; i++) {
        if (cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) && cube.parts[2][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) && cube.parts[1][2][2].getSide(5) != cube.parts[1][2][1].getSide(5) && cube.parts[1][2][0].getSide(5) != cube.parts[1][2][1].getSide(5)) {
            turnLeftRight(0, false);
            PifPaf1();
            turnLeftRight(0, true);
        } else if (cube.parts[0][2][1].getSide(5) == cube.parts[1][2][1].getSide(5) && cube.parts[2][2][1].getSide(5) != cube.parts[1][2][1].getSide(5) && cube.parts[1][2][2].getSide(5) == cube.parts[1][2][1].getSide(5) && cube.parts[1][2][0].getSide(5) != cube.parts[1][2][1].getSide(5)) {
            turnLeftRight(0, false);
            PifPaf1();
            PifPaf1();
            turnLeftRight(0, true);
        } else if (cube.parts[0][2][1].getSide(5) != cube.parts[1][2][1].getSide(5) && cube.parts[2][2][1].getSide(5) != cube.parts[1][2][1].getSide(5) && cube.parts[1][2][2].getSide(5) != cube.parts[1][2][1].getSide(5) && cube.parts[1][2][0].getSide(5) != cube.parts[1][2][1].getSide(5)) {
            turnLeftRight(0, false);
            PifPaf1();
            turnLeftRight(0, true);
            turnHorizontal(2, true);
            turnHorizontal(2, true);
            turnLeftRight(0, false);
            PifPaf1();
            PifPaf1();
            turnLeftRight(0, true);
        } else {
            rotateCube();
        }
        if (FirstCrosscheck1()) {
            break;
        }
    }
    std::cout << "Solved Second Cross\n";
}
void Window::ThirdLayer () {
    while (ThirdLayercheck() == false) {
        if (cube.parts[0][2][2].getSide(5) == cube.parts[0][1][1].getSide(1)) {
            PifPaf1();
            PifPaf1();
            PifPaf1();
            PifPaf1();
        } else if (cube.parts[0][2][2].getSide(2) == cube.parts[0][1][1].getSide(1)) {
            PifPaf1();
            PifPaf1();
        }
        turnVertical(0, true);
    }
    std::cout << "Solved Third Layer\n";
}
void Window::FinalVertices () {
    int counter = 0;
    int counter2 = 0;
    while (FinalVerticescheck() == false) {
        while (counter < 2) {
            counter = 0;
            turnHorizontal(2, true);
            cube.parts[0][2][1].getSide(1) == cube.parts[0][1][1].getSide(1) ? counter++ : counter;
            cube.parts[1][2][0].getSide(0) == cube.parts[1][1][0].getSide(0) ? counter++ : counter;
            cube.parts[1][2][2].getSide(2) == cube.parts[1][1][2].getSide(2) ? counter++ : counter;
            cube.parts[2][2][1].getSide(3) == cube.parts[2][1][1].getSide(3) ? counter++ : counter;
        }
        if (cube.parts[1][2][0].getSide(0) == cube.parts[2][1][1].getSide(3) && cube.parts[2][2][1].getSide(3) == cube.parts[1][1][0].getSide(0)) {
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnLeftRight(0, true);
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnLeftRight(0, false);
            turnVertical(2, true);
            turnVertical(2, true);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnHorizontal(2, false);
        } else if (cube.parts[2][2][1].getSide(3) == cube.parts[0][1][1].getSide(1) && cube.parts[0][2][1].getSide(1) == cube.parts[2][1][1].getSide(3)) {
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnLeftRight(0, true);
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnLeftRight(0, false);
            turnVertical(2, true);
            turnVertical(2, true);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnHorizontal(2, false);
            turnHorizontal(2, true);
            turnHorizontal(2, true);
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnLeftRight(0, true);
            turnVertical(2, true);
            turnHorizontal(2, true);
            turnVertical(2, false);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnLeftRight(0, false);
            turnVertical(2, true);
            turnVertical(2, true);
            turnHorizontal(2, false);
            turnVertical(2, false);
            turnHorizontal(2, false);
            turnHorizontal(2, false);
        }
        rotateCube();
        // if (counter2 < 5) {
        //     rotateCube();
        //     counter++;
        // } else {
        //     std::cout << "Solution has cycled: shuffling and resolving\n";
        //     counter = 0;
        //     Shuffle();
        //     Solve();
        //     return;
        // }
    }
    std::cout << "Solved Final Vertices\n";
}
void Window::FinalEdges () {
    int counter = 0;
    while (FinalEdgescheck() == false) {
        for (int i = 0; i < 4; i++) {
            if (cube.parts[0][2][2].getSide(1) == cube.parts[0][1][1].getSide(1) && cube.parts[0][2][2].getSide(2) == cube.parts[1][1][2].getSide(2)) {
                break;
            }
            rotateCube();
            // if (counter < 5) {
            //     rotateCube();
            //     counter++;
            // } else {
            //     std::cout << "Solution has cycled: shuffling and resolving\n";
            //     counter = 0;
            //     Shuffle();
            //     Solve();
            //     return;
            // }
        }
        turnLeftRight(0, true);
        turnLeftRight(1, true);
        turnLeftRight(2, true);
        turnHorizontal(2, true);
        turnHorizontal(2, true);
        turnVertical(2, true);
        turnHorizontal(2, true);
        turnHorizontal(2, true);
        turnVertical(2, false);
        turnLeftRight(0, false);
        turnLeftRight(0, false);
        turnHorizontal(2, true);
        turnHorizontal(2, true);
        turnVertical(0, true);
        turnHorizontal(2, true);
        turnHorizontal(2, true);
        turnVertical(0, false);
        turnLeftRight(0, false);
        turnLeftRight(0, false);
        turnLeftRight(0, false);
        turnLeftRight(1, false);
        turnLeftRight(2, false);
    }
    turnVertical(0, true);
    turnVertical(1, true);
    turnVertical(2, true);
    turnVertical(0, true);
    turnVertical(1, true);
    turnVertical(2, true);
    std::cout << "Completely solved Rubik's Cube\n";
}