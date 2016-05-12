#include "main.h"
#include "PlayerCharacter.h"
#include "PlayEngine.h"
#include "InputManager.h"

namespace dxshoot{

PlayerCharacter::PlayerCharacter()
	: Character()
{
	position = Vector2(128.0f, 128.0f);
	collisionRect = Vector2(4.0f, 4.0f);
	color = DxLib::GetColor(255, 255, 255);
}


PlayerCharacter::~PlayerCharacter()
{
	Character::~Character();
}


void PlayerCharacter::update()
{
	position += InputManager::getInstance().getDirection() * Speed;
}


}