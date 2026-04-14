#pragma once
#include "KamataEngine.h"

class GameScene {
	public:
		GameScene();			//コンストラクタ
		~GameScene();			//デストラクタ
	    void Initialize();		//初期化処理
		void Update();			//更新処理
	    void DrawBGSprite();	//背景Spriteの描画処理
		void DrawFGSprite();	//前景Spriteの描画処理
	    void DrawModel();		//Modelの描画処理
	    void ImGuiDraw();		//ImGuiの描画処理

	private:
	    KamataEngine::WorldTransform worldTransform_;//ワールドトランスフォーム(世界の座標)
		KamataEngine::Camera camera_;//カメラ
	    KamataEngine::Input* input_ = nullptr;// 入力
	    KamataEngine::ImGuiManager* imguiManager_ = nullptr;// ImGuiManagerのインスタンス

		uint32_t textureHandle_;//テクスチャハンドル
	    KamataEngine::Sprite* sprite_;//スプライト

		KamataEngine::Model* model_;//モデル
};
