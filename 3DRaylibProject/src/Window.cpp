#include "Window.h"

void Window::Startup(void(*start)())
{
	start();
}

void Window::CreateWindow(int width, int height, char* title, int fps)
{
	InitWindow(width, height, title);
	InitAudioDevice();
	SetTargetFPS(fps);
	bgColor = SKYBLUE;
}

void Window::Update(void(*update)())
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(bgColor);
		update();
		DrawFPS(10, 10);
		EndDrawing();
	}
}

void Window::SetBGColor(Color color)
{
	ClearBackground(color);
}

void Window::Shutdown(void(*shutdown)())
{
	shutdown();
	CloseAudioDevice();
	CloseWindow();
}