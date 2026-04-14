#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() { 
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();
	//ImGuiManagerインスタンスの取得
	imguiManager_ = ImGuiManager::GetInstance();
}

void GameScene::Update() {
	// ワールド変換行列の転送
	worldTransform_.TransferMatrix();
}

void GameScene::DrawBGSprite() {}

void GameScene::DrawFGSprite() {}

void GameScene::DrawModel() {}

void GameScene::ImGuiDraw() { 
	//ImGui受付開始
	imguiManager_->Begin();

	ImGui::Begin("Game Scene");
	ImGui::End();

	//ImGui受付終了
	imguiManager_->End();

	//ImGuiの描画
	imguiManager_->Draw();
}
