#include "TexturedModel.h"

TexturedModel::TexturedModel(const RawModel& rawModel, const Texture& texture) : rawModel(rawModel), texture(texture) {}


RawModel TexturedModel::getRawModel() const {
    return rawModel;
}

Texture TexturedModel::getTexture() const {
    return texture;
}
