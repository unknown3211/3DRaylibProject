#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include "raylib.h"
#include "Camera.h"

class Player
{
public:
	Vector3 position;
	float speed;
	float rotation;
	float radius;
	bool dead;
	Model model;
	std::string name;
	bool isGrounded;
	bool isColliding;

	Player(Vector3 start_position);
	~Player();
	void UpdatePlayer();
	void LoadPlayerModel(GameCamera& camera);
};


#endif