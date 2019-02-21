#ifndef GLSOLARSYSTEM_UTIL_H
#define GLSOLARSYSTEM_UTIL_H

#include <vector>
#include <string>
#include <GL/glew.h>

class Util {

public:
    static std::string readFile(const std::string& path);
    static void checkShaderError(GLuint shader, GLuint status, bool isProgram, const std::string& errorMessage);
    static const std::vector<std::string> split(const std::string& s, const char& c);
};


#endif //GLSOLARSYSTEM_UTIL_H
