#ifndef GLSOLARSYSTEM_RAWMODEL_H
#define GLSOLARSYSTEM_RAWMODEL_H


class RawModel {

public:

    RawModel(int vaoID, int vertexCount);

    int getVaoID() const;

    int getVertexCount() const;

private:
    int vaoID;
    int vertexCount;
};


#endif //GLSOLARSYSTEM_RAWMODEL_H
