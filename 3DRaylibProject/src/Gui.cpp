#include "Gui.h"

void GUI::Init()
{
	rlImGuiSetup(true);
}

void KeybindsWindow()
{
    static bool keybindsShown = false;

    if (ImGui::Button("Controls"))
    {
        keybindsShown = !keybindsShown;
    }

    if (keybindsShown)
    {
        if (ImGui::CollapsingHeader("General Controls"))
        {
            ImGui::BulletText("[TAB]: Cursor Toggle");
            ImGui::BulletText("[Y]: Editor Toggle");
            ImGui::BulletText("[W,A,S,D]: Movement");
        }
    }
}

void GUI::Update(Window* window)
{
    rlImGuiBegin();

    ImVec2 displaySize = ImGui::GetIO().DisplaySize;
    float sidebarWidth = 355.0f;

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(sidebarWidth, displaySize.y));

    ImGui::Begin("UD EDITOR", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    KeybindsWindow();

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