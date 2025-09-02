#include "Camera.h"

GameCamera::GameCamera()
{
    camera.position = Vector3{ 0.0f, 2.0f, 4.0f };
    camera.target = Vector3{ 0.0f, 2.0f, 0.0f };
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    cameraMode = CAMERA_FIRST_PERSON;
}