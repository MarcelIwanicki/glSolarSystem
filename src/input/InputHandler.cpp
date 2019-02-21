#include "InputHandler.h"

static constexpr unsigned int MAX_KEYS = 1024;
static constexpr unsigned int MAX_MOUSEBUTTONS = 32;

static bool keys[MAX_KEYS] = {false};
static bool mousebuttons[MAX_MOUSEBUTTONS] = {false};

static int mouse_x;
static int mouse_y;

bool InputHandler::isKeyPressed(unsigned int key) {
    if(key >= 0 && key < MAX_KEYS)
        return keys[key];
    else
        return false;
}

bool InputHandler::isMouseButtonPressed(unsigned int mousebutton) {
    if(mousebutton >= 0 && mousebutton < MAX_MOUSEBUTTONS)
        return mousebuttons[mousebutton];
    else
        return false;
}

void InputHandler::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    keys[key] = action != GLFW_RELEASE;
}

void InputHandler::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
    mousebuttons[button] = action != GLFW_RELEASE;
}

void InputHandler::cursorPositionCallback(GLFWwindow *window, double xpos, double ypos) {
    mouse_x = xpos;
    mouse_y = ypos;
}

int InputHandler::getMouseX() {
    return mouse_x;
}

int InputHandler::getMouseY() {
    return mouse_y;
}
