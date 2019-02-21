#include "Display.h"
#include "../input/InputHandler.h"

#include <iostream>

Display::Display(int width, int height, const std::string &title) {
    this->width = width;
    this->height = height;

    initGlfw();
    initWindow(title);
    initGlew();
    initOpenglFlags();

    running = true;
}

void Display::initGlfw() {

    if(!glfwInit())
        std::cerr << "Failed to initialize glfw" << std::endl;

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

}

void Display::initWindow(const std::string &title) {
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if(!window)
        std::cerr << "ERROR: Couldn't create window" << std::endl;

    glfwMakeContextCurrent(window);
}

void Display::initGlew() {
    GLenum status = glewInit();

    if(status != GLEW_OK)
        std::cerr << "ERROR: Glew not ok" << std::endl;

    glewExperimental = GL_TRUE;
}

void Display::initOpenglFlags() {
    glEnable(GL_DEPTH_TEST);
}

Display::~Display() {
    glfwDestroyWindow(window);
    glfwMakeContextCurrent(nullptr);
    glfwTerminate();
}

void Display::clear(float r, float g, float b, float a) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(r, g, b, a);
}

void Display::update() {
    if(!glfwWindowShouldClose(window))
    {
        glfwGetWindowSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glfwSetKeyCallback(window, InputHandler::keyCallback);
        glfwSetMouseButtonCallback(window, InputHandler::mouseButtonCallback);
        glfwSetCursorPosCallback(window, InputHandler::cursorPositionCallback);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    else
        running = false;
}

bool Display::isRunning() {
    return running;
}

int Display::getWidth(){
    return width;
}

int Display::getHeight() {
    return height;
}

GLFWwindow *Display::getWindow() const {
    return window;
}
