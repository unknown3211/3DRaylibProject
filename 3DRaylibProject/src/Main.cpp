#include <iostream>
#include "Window.h"
#include "Camera.h"
#include "Level.h"
#include "Model.h"
#include "Animtest.h"
#include "Gui.h"

Window* window;
GameCamera* gamecamera;
Level* level;
GameModel* gamemodel;
GUI* gui;

int s_width = 1920;
int s_height = 1080;
int s_fps = 144;
char* title = "3D Game Test Project";
static bool cursor = true;

static void OnStart()
{
    window = new Window();
    gamecamera = new GameCamera();
    level = new Level();
    gamemodel = new GameModel();
    gui = new GUI;

    window->CreateWindow(s_width, s_height, title, s_fps);
    level->LoadDefaultGround();
    gamemodel->LoadDefaultModel(TORUS);

    gui->Init();
}

static void OnUpdate()
{;
    float deltaTime = GetFrameTime();
    BeginMode3D(gamecamera->camera);
    
    if (!cursor)
    {
        UpdateCamera(&gamecamera->camera, gamecamera->cameraMode);
    }

    level->DrawDefaultGround();
    gamemodel->DrawDefaultModel();

    if (IsKeyPressed(KEY_TAB))
    {
        cursor = !cursor;
        if (cursor)
            EnableCursor();
        else
            DisableCursor();
    }

    EndMode3D();

    if (IsKeyPressed(KEY_Y))
    {
        gui->ToggleEditor(!gui->editorOpen);
    }

    if (gui->editorOpen)
    {
        gui->Update(window);
    }
}

static void OnShutdown()
{
    level->Shutdown();
    gamemodel->Shutdown();
    gui->Shutdown();

    delete window;
    delete gamecamera;
    delete level;
    delete gamemodel;
    delete gui;

    window = nullptr;
    gamecamera = nullptr;
    level = nullptr;
    gamemodel = nullptr;
    gui = nullptr;
}

int main(void)
{
    window->Startup(OnStart);
    window->Update(OnUpdate);
    window->Shutdown(OnShutdown);
    return 0;
}