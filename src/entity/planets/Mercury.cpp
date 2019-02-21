#include "Mercury.h"
#include "../../util/Constants.h"

Mercury::Mercury(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_MERCURY)), glm::vec3(Constants::D_FROM_EARTH_MERCURY, 0, -25.0), M_PI / 2, 0, 0, Constants::R_MERCURY){}

