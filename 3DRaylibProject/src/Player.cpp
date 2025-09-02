#include "Player.h"

Player::Player(Vector3 start_position)
{
	position = start_position;
	speed = 5.0f;
	radius = 1.5f;
	rotation = 0.1f;
	dead = false;
	model = LoadModel("");
	name = "DevChar";
	isGrounded = true;
	isColliding = false;
}

void Player::UpdatePlayer()
{
	DrawModel(model, position, 2.0f, RED);
}

Player::~Player()
{
	UnloadModel(model);
}