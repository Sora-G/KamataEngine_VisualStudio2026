#include <Windows.h>
#include "KamataEngine.h"

using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	//DirectXCommonインスタンス取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	//KamataEngineの初期化
	KamataEngine::Initialize(L"LE4D_11_スズキ_ソラ_SR2");

	//メインループ
	while (true) {
		//KamataEngineの更新
		if (KamataEngine::Update()) {
			break;
		}
		//描画開始処理
		dxCommon->PreDraw();

		//描画終了
		dxCommon->PostDraw();
	}

	//KamataEngineの終了処理
	KamataEngine::Finalize();

	return 0;
}
