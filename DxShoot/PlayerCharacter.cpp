#include "main.h"
#include "PlayerCharacter.h"
#include "PlayEngine.h"
#include "InputManager.h"

namespace dxshoot{

PlayerCharacter::PlayerCharacter()
{
	pos = Vector2(240.0f, 300.0f);
	image = PlayEngine::getInstance().getImages().load("chara_test.png");
}


PlayerCharacter::~PlayerCharacter()
{
}


void PlayerCharacter::update()
{
	pos = pos + InputManager::getInstance().getDirection();
}


void PlayerCharacter::draw()
{
	DxLib::DrawGraphF(pos.x, pos.y, image, TRUE);
}

}