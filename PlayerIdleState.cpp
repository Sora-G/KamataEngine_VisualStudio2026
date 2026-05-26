#include "PlayerIdleState.h"
#include "KamataEngine.h"
#include "Player.h"
#include "PlayerMoveState.h"

using namespace KamataEngine;

void PlayerIdleState::Update(Player* player) {
	Input* input = player->GetInput();

	if (input->PushKey(DIK_W) || 
		input->PushKey(DIK_A) || 
		input->PushKey(DIK_S) || 
		input->PushKey(DIK_D)) {

		player->ChangeState(new PlayerMoveState());
		return;
	}
}
