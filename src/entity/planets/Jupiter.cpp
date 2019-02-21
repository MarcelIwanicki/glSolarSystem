#include "Jupiter.h"
#include "../../util/Constants.h"

Jupiter::Jupiter(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_JUPITER)), glm::vec3(Constants::D_FROM_EARTH_JUPITER, 0, -25.0), M_PI / 2, 0, 0, Constants::R_JUPITER){}

