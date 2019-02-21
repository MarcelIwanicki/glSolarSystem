#include "RawModel.h"

RawModel::RawModel(int vaoID, int vertexCount) : vaoID(vaoID), vertexCount(vertexCount) {}

int RawModel::getVaoID() const {
    return vaoID;
}

int RawModel::getVertexCount() const {
    return vertexCount;
}
