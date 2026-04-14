#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() { 
	 // ImGuiManagerインスタンスの取得
	imguiManager_ = ImGuiManager::GetInstance();
}

void GameScene::Update() {}

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
