#include "Sun.h"
#include "../../util/Constants.h"

Sun::Sun(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_SUN)), glm::vec3(Constants::D_FROM_EARTH_SUN, 0, -25.0), M_PI / 2, 0, 0, Constants::R_SUN){}
