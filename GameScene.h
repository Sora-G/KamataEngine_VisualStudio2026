#pragma once
#include "KamataEngine.h"

class GameScene {
public:
		GameScene();		//コンストラクタ
		~GameScene();		//デストラクタ
	    void Initialize();	//初期化処理
		void Update();		//更新処理
		void DrawSprite();	//Spriteの描画処理
	    void DrawModel();	//Modelの描画処理

	private:
};
