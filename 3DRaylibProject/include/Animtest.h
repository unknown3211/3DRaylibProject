#pragma once

#include <iostream>
#include "raylib.h"

class AnimTest
{
public:
	Model testAnim;
	Vector3 testPos;
	ModelAnimation* modelAnimations;
	ModelAnimation anim;
	int animsCount = 0;
	unsigned int animIndex = 0;
	unsigned int animCurrentFrame = 0;

	void LoadModelWithAnimation(const char* file, Vector3 position);
	void UpdateModelWithAnimation();
	void ShutdownModelWithAnimation();
};