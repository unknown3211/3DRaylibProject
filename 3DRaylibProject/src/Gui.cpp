#include "Gui.h"

void GUI::Init()
{
	rlImGuiSetup(true);
}

void GUI::Update(Window* window)
{
    rlImGuiBegin();
    ImGui::Begin("UD EDITOR"); // title
 
   // if (ImGui::Button("> Play Game"))
   // {
   //     ToggleEditor(false);
   // }

    float color[3] = {
        window->bgColor.r / 255.0f,
        window->bgColor.g / 255.0f,
        window->bgColor.b / 255.0f
    };

    if (ImGui::ColorEdit3("Background Color", color))
    {
        window->bgColor = Color {
            (unsigned char)(color[0] * 255),
            (unsigned char)(color[1] * 255),
            (unsigned char)(color[2] * 255),
            255
        };
    }

    ImGui::End();
    rlImGuiEnd();
}

void GUI::ToggleEditor(bool show)
{
    editorOpen = show;
    if (show)
    {
        editorOpen = true;
    }
    else
    {
        editorOpen = false;
    }
}


void GUI::Shutdown()
{
	rlImGuiShutdown();
}