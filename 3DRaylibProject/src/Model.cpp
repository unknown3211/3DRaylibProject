#include "Model.h"

void LoadMissingTexture(Model* model)
{
	Texture m_texture = LoadTexture(RESOURCES_PATH "textures/missingtexture.png");
	model->materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = m_texture;
    TraceLog(LOG_ERROR, "Missing Textures For Model");
}

void GameModel::CustomModel(const char* filepath)
{
    LoadModel(filepath);
}

void GameModel::CustomModelT(const char* m_filepath, const char* t_filepath)
{
	model = LoadModel(m_filepath);
	texture = LoadTexture(t_filepath);
	model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void GameModel::Shutdown()
{
    UnloadModel(model);
    UnloadTexture(texture);
}

void GameModel::LoadDefaultModel(DModelTypes modeltype)
{
    switch (modeltype)
    {
    case TORUS:
        model = LoadModelFromMesh(GenMeshTorus(0.4f, 1.0f, 16, 32));
        break;

    case CUBE:
        model = LoadModelFromMesh(GenMeshCube(1.0f, 1.0f, 1.0f));
        break;

    case SPHERE:
        model = LoadModelFromMesh(GenMeshSphere(0.5f, 32, 32));
        break;
    }

    texture = LoadTexture(RESOURCES_PATH "textures/texel_checker.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    if (texture.id == 0)
    {
        LoadMissingTexture(&model);
    }
}

void GameModel::DrawDefaultModel()
{
    DrawModel(model, Vector3{ 0.0f, 2.0f, 0.0f }, 1.0f, WHITE);
}