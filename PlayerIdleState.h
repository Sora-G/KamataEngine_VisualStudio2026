#pragma once
#include "PlayerState.h"
class PlayerIdleState : public PlayerState {
public:
	void Update(Player* player) override; // 更新処理
};
