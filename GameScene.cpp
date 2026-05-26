#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	delete player_;
}

void GameScene::Initialize() { 
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	//カメラの初期化
	camera_.translation_ = Vector3(0.0f, 30.0f, 0.0f);
	camera_.rotation_ = Vector3(1.59f, 0.0f, 0.0f);
	camera_.Initialize();
	
	//入力のインスタンス取得
	input_ = Input::GetInstance();

	// ImGuiManagerインスタンスの取得
	imguiManager_ = ImGuiManager::GetInstance();

	player_ = new Player(); // プレイヤーの生成
	player_->Initialize();  // プレイヤーの初期化
}

void GameScene::Update() {
	// ワールド変換行列の転送
	worldTransform_.TransferMatrix();
	
	//カメラ行列の更新＆転送
	camera_.UpdateMatrix();
	camera_.TransferMatrix();

	// プレイヤーの更新
	player_->Update();
}

void GameScene::DrawBGSprite() {
}

void GameScene::DrawFGSprite() {}

void GameScene::DrawModel() {
	// プレイヤーの描画
	player_->Draw(camera_);
}

void GameScene::ImGuiDraw() { 
	//ImGui受付開始
	imguiManager_->Begin();

	ImGui::Begin("Game Scene");
	ImGui::Text("Player Position: (%.2f, %.2f, %.2f)", player_->GetWorldTransform().translation_.x, player_->GetWorldTransform().translation_.y, player_->GetWorldTransform().translation_.z);
	ImGui::End();

	//ImGui受付終了
	imguiManager_->End();

	//ImGuiの描画
	imguiManager_->Draw();
}
