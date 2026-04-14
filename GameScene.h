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
	    KamataEngine::ImGuiManager* imguiManager_ = nullptr;// ImGuiManagerのインスタンス
};
