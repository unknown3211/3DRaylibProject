#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H

#include "raylib.h"

class Window
{
public:
	Color bgColor;
	void Startup(void(*start)());
	void CreateWindow(int width, int height, char* title, int fps);
	void Update(void(*update)());
	void Shutdown(void(*shutdown)());
	void SetBGColor(Color color);
};


#endif