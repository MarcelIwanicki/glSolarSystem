cmake_minimum_required(VERSION 3.13)
project(glSolarSystem)

set(PROJECT_NAME "glSolarSystem")
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES lib/stb_image/stb_image.cpp lib/stb_image/stb_image.h lib/imgui/imgui_impl_glfw.h lib/imgui/imgui_impl_glfw.cpp lib/imgui/imconfig.h lib/imgui/imgui.cpp lib/imgui/imgui.h lib/imgui/imgui_demo.cpp lib/imgui/imgui_draw.cpp lib/imgui/imgui_internal.h lib/imgui/imgui_widgets.cpp lib/imgui/imstb_rectpack.h lib/imgui/imstb_textedit.h lib/imgui/imstb_truetype.h lib/imgui/imgui_impl_opengl3.cpp lib/imgui/imgui_impl_opengl3.h example/test.cpp src/display/Display.cpp src/display/Display.h src/input/InputHandler.cpp src/input/InputHandler.h src/util/Util.cpp src/util/Util.h src/util/Math.cpp src/util/Math.h src/entity/Camera.cpp src/entity/Camera.h src/model/RawModel.cpp src/model/RawModel.h src/model/Loader.cpp src/model/Loader.h src/render/Renderer.cpp src/render/Renderer.h src/shader/Shader.cpp src/shader/Shader.h src/shader/PlanetShader.cpp src/shader/PlanetShader.h src/texture/Texture.cpp src/texture/Texture.h src/model/TexturedModel.cpp src/model/TexturedModel.h src/entity/Entity.cpp src/entity/Entity.h src/model/OBJLoader.cpp src/model/OBJLoader.h src/entity/Light.cpp src/entity/Light.h src/shader/SunShader.cpp src/shader/SunShader.h src/util/Constants.h src/entity/Sphere.cpp src/entity/Sphere.h src/entity/planets/Sun.cpp src/entity/planets/Sun.h src/entity/planets/Mercury.cpp src/entity/planets/Mercury.h src/entity/planets/Venus.cpp src/entity/planets/Venus.h src/entity/planets/Earth.cpp src/entity/planets/Earth.h src/entity/planets/Mars.cpp src/entity/planets/Mars.h src/entity/planets/Jupiter.cpp src/entity/planets/Jupiter.h src/entity/planets/Saturn.cpp src/entity/planets/Saturn.h src/entity/planets/Uranus.cpp src/entity/planets/Uranus.h src/entity/planets/Neptune.cpp src/entity/planets/Neptune.h src/entity/Skybox.cpp src/entity/Skybox.h src/shader/RegularShader.cpp src/shader/RegularShader.h src/gui/Gui.cpp src/gui/Gui.h src/main/SolarSystem.cpp src/main/SolarSystem.h src/entity/planets/SaturnRings.cpp src/entity/planets/SaturnRings.h src/audio/AudioMaster.cpp src/audio/AudioMaster.h src/audio/AudioSource.cpp src/audio/AudioSource.h src/util/Res.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(GLEW REQUIRED glew)
pkg_search_module(OPENAL REQUIRED openal)
pkg_search_module(ALUT REQUIRED freealut)

include_directories(${GLEW_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${OPENAL_INCLUDE_DIRS} ${ALUT_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${GLEW_STATIC_LIBRARIES} ${GLFW_STATIC_LIBRARIES} ${OPENAL_STATIC_LIBRARIES} ${ALUT_STATIC_LIBRARIES})
