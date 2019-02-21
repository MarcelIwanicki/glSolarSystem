#include "Gui.h"

Gui::Gui(Display* display) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(display->getWindow(), true);
    ImGui_ImplOpenGL3_Init("#version 400 core");
    ImGui::StyleColorsClassic();

}

Gui::~Gui() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void Gui::initFrame() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Gui::update() {
    if(freePressed)
        focusState = FocusState::NONE;
    else if(sunPressed)
        focusState = FocusState::SUN;
    else if(mercuryPressed)
        focusState = FocusState::MERCURY;
    else if(venusPressed)
        focusState = FocusState::VENUS;
    else if(earthPressed)
        focusState = FocusState::EARTH;
    else if(marsPressed)
        focusState = FocusState::MARS;
    else if(jupiterPressed)
        focusState = FocusState::JUPITER;
    else if(saturnPressed)
        focusState = FocusState::SATURN;
    else if(uranusPressed)
        focusState = FocusState::URANUS;
    else if(neptunePressed)
        focusState = FocusState::NEPTUNE;

    displayCameraWindow();
    displaySettingsWindow();
    displayInfoWindow();
}

void Gui::displayCameraWindow() {
    ImGui::Begin("CAMERA POSITION");

    button("FREE   ", "Press to free the camera", &freePressed);
    button("Sun    ", "Press to observe the Sun", &sunPressed);
    button("Mercury", "Press to observe Mercury", &mercuryPressed);
    button("Venus  ", "Press to observe Venus", &venusPressed);
    button("Earth  ", "Press to observe Earth", &earthPressed);
    button("Mars   ", "Press to observe Mars", &marsPressed);
    button("Jupiter", "Press to observe Jupiter", &jupiterPressed);
    button("Saturn ", "Press to observe Saturn", &saturnPressed);
    button("Uranus ", "Press to observe Uranus", &uranusPressed);
    button("Neptune", "Press to observe Neptune", &neptunePressed);

    ImGui::End();
}

void Gui::displaySettingsWindow() {
    ImGui::Begin("SETTINGS");

    ImGui::SliderFloat("Volume", &volumeScale , 0.0, 1.0);
    ImGui::SliderFloat("Time speed", &timeScale , 0.0, 30.0);
    ImGui::SliderFloat("Light intensity", &lightIntensityScale, 0.01, 10.0);
    ImGui::ColorEdit3("Light color", colors);

    ImGui::End();
}

void Gui::displayInfoWindow() {
    ImGui::Begin("INFO");

    switch (focusState) {
        case FocusState::NONE: {
            ImGui::Text("Free camera, use:");
            ImGui::Text("WSAD          to move around");
            ImGui::Text("ARROWS        to rotate camera");
            ImGui::Text("SHIFT / SPACE to move up / down");
            ImGui::Text("LEFT CTRL     to increase velocity");
        }
        break;

        case FocusState::SUN: {
            ImGui::Text("SUN");
            ImGui::Text("Radius:       695 508 km");
            ImGui::Text("Mass:         1,989 * 10^30 kg");
            ImGui::Text("Temperature:  5 778 K = 5 504 C");
            ImGui::Text("Age:          4,603 * 10^9 years");
            ImGui::Text("g:            274 m/s²");
        }
        break;

        case FocusState::MERCURY: {
            ImGui::Text("MERCURY");
            ImGui::Text("Radius:       2 440 km");
            ImGui::Text("Mass:         3,285 * 10^23 kg");
            ImGui::Text("Temperature:  700 K = 427 C");
            ImGui::Text("Age:          4,503 * 10^9 years");
            ImGui::Text("g:            3,7 m/s²");
        }
        break;

        case FocusState::VENUS: {
            ImGui::Text("VENUS");
            ImGui::Text("Radius:       6 052 km");
            ImGui::Text("Mass:         4,867 * 10^24 kg");
            ImGui::Text("Temperature:  735 K = 462 C");
            ImGui::Text("Age:          4,503 * 10^9 years");
            ImGui::Text("g:            8,87 m/s²");
        }
        break;

        case FocusState::EARTH: {
            ImGui::Text("EARTH");
            ImGui::Text("Radius:       6 371 km");
            ImGui::Text("Mass:         5,972 * 10^24 kg");
            ImGui::Text("Temperature:  287 K = 14 C");
            ImGui::Text("Age:          4,543 * 10^9 years");
            ImGui::Text("g:            9,81 m/s²");
        }
        break;

        case FocusState::MARS: {
            ImGui::Text("MARS");
            ImGui::Text("Radius:       3 390 km");
            ImGui::Text("Mass:         6,39 * 10^23 kg");
            ImGui::Text("Temperature:  213 K = -60 C");
            ImGui::Text("Age:          4,603 * 10^9 years");
            ImGui::Text("g:            3,71 m/s²");
        }
        break;

        case FocusState::JUPITER: {
            ImGui::Text("JUPITER");
            ImGui::Text("Radius:       69 911 km");
            ImGui::Text("Mass:         1,898 * 10^27 kg");
            ImGui::Text("Temperature:  128 K = -145 C");
            ImGui::Text("Age:          4,503 * 10^9 years");
            ImGui::Text("g:            24,79 m/s²");
        }
        break;

        case FocusState::SATURN: {
            ImGui::Text("SATURN");
            ImGui::Text("Radius:       58 232 km");
            ImGui::Text("Mass:         5,683 * 10^26 kg");
            ImGui::Text("Temperature:  95 K = -178 C");
            ImGui::Text("Age:          4,603 * 10^9 years");
            ImGui::Text("g:            10,44 m/s²");
        }
        break;

        case FocusState::URANUS: {
            ImGui::Text("URANUS");
            ImGui::Text("Radius:       25 362 km");
            ImGui::Text("Mass:         8,681 * 10^25 kg");
            ImGui::Text("Temperature:  49 K = -224 C");
            ImGui::Text("Age:          4,503 * 10^9 years");
            ImGui::Text("g:            8,87 m/s²");
        }
        break;

        case FocusState::NEPTUNE: {
            ImGui::Text("NEPTUNE");
            ImGui::Text("Radius:       24 622 km");
            ImGui::Text("Mass:         1,024 * 10^26 kg");
            ImGui::Text("Temperature:  59 K = -214 C");
            ImGui::Text("Age:          4,503 * 10^9 years");
            ImGui::Text("g:            11,15 m/s²");
        }
        break;
    }

    ImGui::End();
}

void Gui::render()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::button(const std::string& label, const std::string& info, bool* value)
{
    if(ImGui::Button(label.c_str()))
        *value = true;
    else
        *value = false;
    ImGui::SameLine();
    ImGui::Text(info.c_str());
}

FocusState Gui::getFocusState() const {
    return focusState;
}

float Gui::getTimeScale() const {
    return timeScale;
}

float Gui::getLightIntensityScale() const {
    return lightIntensityScale;
}

float Gui::getVolumeScale() const {
    return volumeScale;
}

const float *Gui::getColors() const {
    return colors;
}
