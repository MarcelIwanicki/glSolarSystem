#ifndef GLSOLARSYSTEM_DISPLAY_H
#define GLSOLARSYSTEM_DISPLAY_H

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Display {

public:
    Display(int width, int height, const std::string& title);
    virtual ~Display();

    void clear(float r, float g, float b, float a);
    void update();

    bool isRunning();
    int getWidth();
    int getHeight();

    GLFWwindow *getWindow() const;

private:
    bool running;
    int width, height;

    GLFWwindow* window;

    void initGlfw();
    void initWindow(const std::string &title);
    void initGlew();
    void initOpenglFlags();
};

#endif //GLSOLARSYSTEM_DISPLAY_H
