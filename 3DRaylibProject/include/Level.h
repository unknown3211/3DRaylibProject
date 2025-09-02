#ifndef LEVEL_CLASS_H
#define LEVEL_CLASS_H

#include <iostream>
#include "raylib.h"
#include "raymath.h"

class Level
{
public:
	Model model;
	Texture texture;

	void LoadMap(char* mapname, Vector3 position);
	void DrawMap();
	void LoadDefaultGround();
	void DrawDefaultGround();
	void LoadPoolDay();
	void Shutdown();
};


#endif