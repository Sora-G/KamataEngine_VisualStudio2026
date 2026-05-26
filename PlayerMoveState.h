#pragma once
#include "PlayerState.h"

class PlayerMoveState : public PlayerState {
public:
	void Update(Player* player) override;
};
