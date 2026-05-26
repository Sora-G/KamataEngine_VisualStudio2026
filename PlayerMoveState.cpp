#include "PlayerMoveState.h"
#include "KamataEngine.h"
#include "Player.h"
#include "PlayerIdleState.h"

using namespace KamataEngine;

void PlayerMoveState::Update(Player* player) {

	Input* input = player->GetInput();
	bool moving = false;

	if (input->PushKey(DIK_W)) {
		player->Move(0.0f, 0.0f, 0.1f);
		moving = true;
	}
	if (input->PushKey(DIK_S)) {
		player->Move(0.0f, 0.0f, -0.1f);
		moving = true;
	}
	if (input->PushKey(DIK_D)) {
		player->Move(0.1f, 0.0f, 0.0f);
		moving = true;
	}
	if (input->PushKey(DIK_A)) {
		player->Move(-0.1f, 0.0f, 0.0f);
		moving = true;
	}

	if (!moving) {
		player->ChangeState(new PlayerIdleState());
	}
}
