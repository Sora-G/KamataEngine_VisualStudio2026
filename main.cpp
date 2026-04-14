#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	#pragma region インスタンスの取得＆初期化

	//DirectXCommonインスタンス取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// KamataEngineの初期化
	KamataEngine::Initialize(L"LE4D_11_スズキ_ソラ_SR2");

	//GameSceneインスタンス生成
	GameScene* gameScene = new GameScene();
	//GameSceneの初期化
	gameScene->Initialize();

#pragma endregion

	//メインループ
	while (true) {
		//KamataEngineの更新
		if (KamataEngine::Update()) {
			break;
		}

		//GameSceneの更新
		gameScene->Update();

		//描画開始処理
		dxCommon->PreDraw();

		#pragma region 背景Spriteの描画処理
	
		// Spriteの描画前処理
		Sprite::PreDraw();

		// GameSceneの描画
		gameScene->DrawBGSprite();

		// Spriteの描画後処理
		Sprite::PostDraw();

#pragma endregion

		//深度バッファのクリア
		dxCommon->ClearDepthBuffer();

		#pragma region Modelの描画処理

		//Modelの描画前処理
		Model::PreDraw();

		gameScene->DrawModel();

		// Modelの描画後処理
		Model::PostDraw();

#pragma endregion


		#pragma region 近景Spriteの描画処理

		// Spriteの描画前処理
		Sprite::PreDraw();

		// GameSceneの描画
		gameScene->DrawFGSprite();

		// Spriteの描画後処理
		Sprite::PostDraw();

#pragma endregion

		//ImGuiの描画
		gameScene->ImGuiDraw();

		//描画終了
		dxCommon->PostDraw();
	}

	//解放処理
	delete gameScene;
	//nullptrを代入しておく
	gameScene = nullptr;

	//KamataEngineの終了処理
	KamataEngine::Finalize();

	return 0;
}
