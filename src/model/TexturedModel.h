#ifndef GLSOLARSYSTEM_TEXTUREDMODEL_H
#define GLSOLARSYSTEM_TEXTUREDMODEL_H

#include "RawModel.h"
#include "../texture/Texture.h"

class TexturedModel {

public:
    TexturedModel(const RawModel& rawModel, const Texture& texture);

    RawModel getRawModel() const;

    Texture getTexture() const;

private:
    RawModel rawModel;
    Texture texture;

};


#endif //GLSOLARSYSTEM_TEXTUREDMODEL_H
