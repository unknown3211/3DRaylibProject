#ifndef MODEL_CLASS_H
#define MODEL_CLASS_H

#include <iostream>
#include "raylib.h"

enum DModelTypes {
	TORUS,
	CUBE,
	SPHERE
};

class GameModel
{
public:
	Model model;
	Texture texture;

	void CustomModel(const char* filepath);
	void CustomModelT(const char* m_filepath, const char* t_filepath);
	void Shutdown();
	void LoadDefaultModel(DModelTypes modeltype);
	void DrawDefaultModel();
};

void LoadMissingTexture(Model* model);

#endif