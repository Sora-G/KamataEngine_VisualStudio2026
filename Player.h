#pragma once
#include "KamataEngine.h"

class PlayerState;

class Player {
public:
    Player();
    ~Player();

    void Initialize();
    void Update();
	void Draw(KamataEngine::Camera& camera);

    void ChangeState(PlayerState* newState);

    KamataEngine::Input* GetInput();

    void Move(float x, float y, float z);

    KamataEngine::WorldTransform& GetWorldTransform() { return worldTransform_; }

private:
    KamataEngine::WorldTransform worldTransform_;
    KamataEngine::Model* model_;
    KamataEngine::Input* input_;

    PlayerState* currentState_;
	PlayerState* nextState_;
};