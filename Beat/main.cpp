#include "main.h"
#include "ImageLoader.h"
#include "PlayEngine.h"
#include "InputManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLib::ChangeWindowMode(TRUE);
	DxLib::SetGraphMode(dxshoot::Size, dxshoot::Size, 32);
	DxLib::SetWindowSize(dxshoot::Size, dxshoot::Size);
	DxLib::SetWindowTextA("beat");
	DxLib::SetBackgroundColor(0, 0, 0);
	DxLib::SetUsePremulAlphaConvertLoad(TRUE);
	if (DxLib::DxLib_Init() == -1)
	{
		return -1;
	}
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	DxLib::SetDrawArea(0, 0, dxshoot::Size, dxshoot::Size);
	dxshoot::init();
	while (DxLib::ProcessMessage() != -1)
	{
		if (dxshoot::InputManager::getInstance().getButton(dxshoot::Button::Esc).push()) {
			dxshoot::PlayEngine::reset();
		}
		dxshoot::update();
		DxLib::ClearDrawScreen();
		dxshoot::draw();
		DxLib::ScreenFlip();
	}
	DxLib::DxLib_End();
	return 0;
}

namespace dxshoot {
const int Size = 256;

void init()
{
	PlayEngine::getInstance().init();

}

void update()
{
	InputManager::getInstance().update();
	PlayEngine::getInstance().update();

}

void draw()
{
	PlayEngine::getInstance().draw();
}

}