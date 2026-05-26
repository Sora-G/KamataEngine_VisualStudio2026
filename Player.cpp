#include "Player.h"
#include "PlayerIdleState.h"

using namespace KamataEngine;

Player::Player() {}

Player::~Player() { delete currentState_; }

void Player::Initialize() {

	worldTransform_.Initialize();

	worldTransform_.translation_ = Vector3(0.0f, 0.0f, 0.0f);

	worldTransform_.TransferMatrix();

	model_ = Model::CreateFromOBJ("cube");

	input_ = Input::GetInstance();

	currentState_ = new PlayerIdleState();
	nextState_ = nullptr;
}

void Player::Update() {
	currentState_->Update(this);

	if (nextState_ != nullptr) {
		delete currentState_;
		currentState_ = nextState_;
		nextState_ = nullptr;
	}

	worldTransform_.TransferMatrix();
}

void Player::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }

void Player::ChangeState(PlayerState* newState) { nextState_ = newState; }

Input* Player::GetInput() { return input_; }

void Player::Move(float x, float y, float z) {
	worldTransform_.translation_.x += x;
	worldTransform_.translation_.y += y;
	worldTransform_.translation_.z += z;
}