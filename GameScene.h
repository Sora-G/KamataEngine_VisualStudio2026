#pragma once
#include "KamataEngine.h"
#include "Scene.h"
#include "Player.h"

class GameScene : public Scene {
	public:
		GameScene();			//コンストラクタ
		~GameScene();			//デストラクタ
	    void Initialize() override;		//初期化処理
		void Update() override;			//更新処理
	    void DrawBGSprite() override;	//背景Spriteの描画処理
		void DrawFGSprite() override;	//前景Spriteの描画処理
	    void DrawModel() override;		//Modelの描画処理
	    void ImGuiDraw() override;		//ImGuiの描画処理

	private:
	    KamataEngine::WorldTransform worldTransform_;//ワールドトランスフォーム(世界の座標)
		KamataEngine::Camera camera_;//カメラ
	    KamataEngine::Input* input_ = nullptr;// 入力
	    KamataEngine::ImGuiManager* imguiManager_ = nullptr;// ImGuiManagerのインスタンス

		Player* player_; // プレイヤー
};
