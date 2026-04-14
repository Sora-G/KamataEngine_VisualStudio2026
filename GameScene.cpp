#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() { 
	//ワールドトランスフォームの初期化
	worldTransform_.Initialize();

	//カメラの初期化
	camera_.translation_ = Vector3(0.0f, 0.0f, -20.0f);
	camera_.Initialize();
	
	#pragma region リソース関連の初期化

	//テクスチャの読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");
	//スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, Vector2(0, 0));

	//モデルの生成
	model_ = Model::CreateFromOBJ("cube");

#pragma endregion

	//ImGuiManagerインスタンスの取得
	imguiManager_ = ImGuiManager::GetInstance();
}

void GameScene::Update() {
	// ワールド変換行列の転送
	worldTransform_.TransferMatrix();
	
	//カメラ行列の更新＆転送
	camera_.UpdateMatrix();
	camera_.TransferMatrix();
}

void GameScene::DrawBGSprite() {
	//uvCheckerを描画
	sprite_->Draw();
}

void GameScene::DrawFGSprite() {}

void GameScene::DrawModel() {
	//cubeを描画
	model_->Draw(worldTransform_, camera_);
}

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
