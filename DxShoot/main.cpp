#include "main.h"
#include "ImageLoader.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLib::ChangeWindowMode(TRUE);
	DxLib::SetWindowTextA("dxshoot");
	DxLib::SetBackgroundColor(100, 149, 237);//cornflowerblue
	DxLib::SetUsePremulAlphaConvertLoad(TRUE);
	if (DxLib::DxLib_Init() == -1)
	{
		return -1;
	}
	DxLib:: SetDrawScreen(DX_SCREEN_BACK);
	dxshoot::init();
	while (DxLib::ProcessMessage() != -1)
	{
		dxshoot::update();
		DxLib::ClearDrawScreen();
		dxshoot::draw();
		DxLib::ScreenFlip();
	}
	DxLib::DxLib_End();
	return 0;
}

namespace dxshoot {
	void init() 
	{

	}

	void update()
	{
	}

	void draw()
	{
	}

}