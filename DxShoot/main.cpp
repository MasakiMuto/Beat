#include <iostream>
#include <DxLib.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	int i = 60;
	SetDrawScreen(DX_SCREEN_BACK);
	while (ProcessMessage() != -1)
	{
		ClearDrawScreen();
		DrawPixel(i, 240, GetColor(255, 255, 0));
		DrawPixel(60, 360, GetColor(255, 255, 0));
		i++;
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}