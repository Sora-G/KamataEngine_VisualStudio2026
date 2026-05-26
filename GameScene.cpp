#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {}

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

	#pragma region リソース関連の初期化

	//テクスチャの読み込み
	textureHandle_ = TextureManager::Load("uvChecker.png");
	//スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, Vector2(0, 0));

	//モデルの生成
	model_ = Model::CreateFromOBJ("cube");

#pragma endregion
}

void GameScene::Update() {

	//カメラの移動
	if (input_->PushKey(DIK_W)) {
		camera_.translation_.z += 0.1f;
	}
	if (input_->PushKey(DIK_S)) {
		camera_.translation_.z -= 0.1f;
	}
	if (input_->PushKey(DIK_D)) {
		camera_.translation_.x += 0.1f;
	}
	if (input_->PushKey(DIK_A)) {
		camera_.translation_.x -= 0.1f;
	}

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
	ImGui::Text("CameraTranslation(%.2f,%.2f,%.2f)", camera_.translation_.x, camera_.translation_.y, camera_.translation_.z);
	ImGui::End();

	//ImGui受付終了
	imguiManager_->End();

	//ImGuiの描画
	imguiManager_->Draw();
}
