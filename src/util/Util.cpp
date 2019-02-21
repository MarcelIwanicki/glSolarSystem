#include "Util.h"
#include <iostream>
#include <fstream>

std::string Util::readFile(const std::string &path)
{
    std::fstream file;
    file.open(path);

    std::string result;
    std::string line;

    if(file.is_open())
        while(file.good())
        {
            getline(file, line);
            result.append(line + "\n");
        }
    else
        std::cerr << "ERROR: Couldn't read file: " << path << std::endl;

    return result;
}

void Util::checkShaderError(GLuint shader, GLuint status, bool isProgram, const std::string &errorMessage)
{
    GLint success;
    GLchar info[512];

    if(isProgram)
        glGetProgramiv(shader, status, &success);
    else
        glGetShaderiv(shader, status, &success);

    if(!success)
    {
        if(isProgram)
        {
            glGetProgramInfoLog(shader, sizeof(info) / sizeof(*info), nullptr, info);
            std::cerr << errorMessage << " | " << info << std::endl;
        }
        else
        {
            glGetShaderInfoLog(shader, sizeof(info) / sizeof(*info), nullptr, info);
            std::cerr << errorMessage << " | " << info << std::endl;
        }
    }
}

const std::vector<std::string> Util::split(const std::string& s, const char& c) {
    std::string buff{""};
    std::vector<std::string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);

    return v;
}
