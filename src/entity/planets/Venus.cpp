#include "Venus.h"
#include "../../util/Constants.h"


Venus::Venus(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_VENUS)), glm::vec3(Constants::D_FROM_EARTH_VENUS, 0, -25.0), M_PI / 2, 0, 0, Constants::R_VENUS){}
