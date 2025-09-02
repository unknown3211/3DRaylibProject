#include "Level.h"
#include "Model.h"

void Level::LoadMap(char* mapname, Vector3 position)
{
	model = LoadModel(mapname);
	model.transform = MatrixTranslate(position.x, position.y, position.z);
}

void Level::DrawMap()
{
	DrawModel(model, { 0.0f, 0.0f, 0.0f }, 1.0f, WHITE);
}

void Level::LoadDefaultGround()
{
	Mesh mesh = GenMeshPlane(50.0f, 50.0f, 1, 1);
	model = LoadModelFromMesh(mesh);

	texture = LoadTexture(RESOURCES_PATH "textures/default_ground.png");
	model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

	if (texture.id == 0)
	{
		LoadMissingTexture(&model);
	}
}

void Level::DrawDefaultGround()
{
	DrawModel(model, Vector3{ 0.0f, 0.0f, 0.0f }, 1.0f, WHITE);
}

void Level::LoadPoolDay()
{
	Vector3 position = { 0.0f, -5.0f, 0.0f };
	LoadMap(RESOURCES_PATH "de_pool.glb", position);
}

void Level::Shutdown()
{
	UnloadModel(model);
	UnloadTexture(texture);
}