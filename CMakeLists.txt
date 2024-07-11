cmake_minimum_required(VERSION 3.20)

project(lab_8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(SOURCE src/main.cpp src/RubikCube.cpp src/Shader.cpp src/Window.cpp src/Solution.cpp src/CubePart.cpp)
add_subdirectory(lib)

add_executable(main ${SOURCE})

target_link_libraries(main glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES} libglew_static glm::glm)
target_include_directories(main PUBLIC ${GLEW_INCLUDES})

if(WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()