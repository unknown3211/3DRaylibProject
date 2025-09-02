#include "AnimTest.h"

void AnimTest::LoadModelWithAnimation(const char* file, Vector3 position)
{
    std::string Path = std::string(RESOURCES_PATH) + file;
    testAnim = LoadModel(Path.c_str());
    testPos = position;
    modelAnimations = LoadModelAnimations(Path.c_str(), &animsCount);
}

void AnimTest::UpdateModelWithAnimation()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) animIndex = (animIndex + 1) % animsCount;
    else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) animIndex = (animIndex + animsCount - 1) % animsCount;
    ModelAnimation anim = modelAnimations[animIndex];
    animCurrentFrame = (animCurrentFrame + 1) % anim.frameCount;
    UpdateModelAnimation(testAnim, anim, animCurrentFrame);
    DrawModel(testAnim, testPos, 0.02f, WHITE);
}

void AnimTest::ShutdownModelWithAnimation()
{
    UnloadModelAnimations(modelAnimations, animsCount);
    UnloadModel(testAnim);
}