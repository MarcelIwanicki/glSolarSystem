#ifndef GLSOLARSYSTEM_SATURNRINGS_H
#define GLSOLARSYSTEM_SATURNRINGS_H

#include "../../model/Loader.h"
#include "../Entity.h"
#include "Saturn.h"

class SaturnRings : public Entity{
public:
    SaturnRings(Loader* loader);
    void update(Saturn* saturn);
};


#endif //GLSOLARSYSTEM_SATURNRINGS_H
