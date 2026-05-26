#pragma once

class Player; // プレイヤークラスの前方宣言

class PlayerState {
public:
	virtual ~PlayerState() {}; // デストラクタ
	virtual void Update(Player* player) = 0; // 更新処理
};
