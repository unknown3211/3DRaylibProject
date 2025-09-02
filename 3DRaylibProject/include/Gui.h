#ifndef GUI_CLASS_H
#define GUI_CLASS_H

#include "rlgui/imgui.h"
#include "rlgui/rlImGui.h"
#include "Window.h"

class GUI
{
public:
	bool editorOpen = false;

	void Init();
	void Update(Window* window);
	void ToggleEditor(bool show);
	void Shutdown();
};

#endif