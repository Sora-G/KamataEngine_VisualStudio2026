#include <Windows.h>
#include "KamataEngine.h"
#include "GameScene.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	//DirectXCommonインスタンス取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//GameSceneインスタンス生成
	GameScene* gameScene = new GameScene();
	//GameSceneの初期化
	gameScene->Initialize();

	//KamataEngineの初期化
	KamataEngine::Initialize(L"LE4D_11_スズキ_ソラ_SR2");

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


		#pragma region Spriteの描画処理
	
		// Spriteの描画前処理
		Sprite::PreDraw();

		// GameSceneの描画
		gameScene->DrawSprite();

		// Spriteの描画後処理
		Sprite::PostDraw();

		#pragma endregion


		#pragma region Modelの描画処理

		//Modelの描画前処理
		Model::PreDraw();

		gameScene->DrawModel();

		// Modelの描画後処理
		Model::PostDraw();

		#pragma endregion


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
