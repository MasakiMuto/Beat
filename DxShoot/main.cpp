#include <iostream>
#include <DxLib.h>
#include "ImageLoader.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	int i = 60;
	SetDrawScreen(DX_SCREEN_BACK);
	dxshoot::ImageLoader loader;
	int tex = loader.load("chara_test.png");
	int tex2 = loader.load("bullet_test.png");
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		DrawGraph(100, 200, tex, TRUE);
		DrawGraph(i, 240, tex2, TRUE);
		i++;
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}