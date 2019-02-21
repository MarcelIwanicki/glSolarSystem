#include "Mars.h"
#include "../../util/Constants.h"

Mars::Mars(Loader *loader) : Sphere(loader, Texture(loader->loadTexture(Res::TEXTURE_MARS)), glm::vec3(Constants::D_FROM_EARTH_MARS, 0, -25.0), M_PI / 2, 0, 0, Constants::R_MARS){}
