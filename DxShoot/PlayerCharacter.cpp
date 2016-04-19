#include "main.h"
#include "PlayerCharacter.h"
#include "PlayEngine.h"
#include "InputManager.h"

namespace dxshoot{

PlayerCharacter::PlayerCharacter()
	: Character("chara_test.png")
{
	position = Vector2(240.0f, 300.0f);
}


PlayerCharacter::~PlayerCharacter()
{
	Character::~Character();
}


void PlayerCharacter::update()
{
	position = position + InputManager::getInstance().getDirection() * Speed;
}


}