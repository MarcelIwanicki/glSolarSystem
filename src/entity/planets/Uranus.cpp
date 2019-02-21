#include "Uranus.h"
#include "../../util/Constants.h"

Uranus::Uranus(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_URANUS)), glm::vec3(Constants::D_FROM_EARTH_URANUS, 0, -25.0), M_PI / 2, 0, 0, Constants::R_URANUS){}