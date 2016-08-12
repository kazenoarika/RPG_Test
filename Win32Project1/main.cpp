#include "DxLib.h"
#include "GameMain.h"

enum {
	WINDOW_WIDTH = 800,
	WINDOW_HEIGHT = 600,
	MAX_SAVEDATE = 3
};

int LoopProcess() {
	if (ScreenFlip() != 0) return false;
	if (ProcessMessage() != 0) return false;
	if (ClearDrawScreen() != 0) return false;
	return true;
}

// プログラムはWinMainから始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (SetGraphMode(
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		16
	) != DX_CHANGESCREEN_OK) return -1;	// ウィンドウサイズを変更する
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) return -1; //ウィンドウ化と初期化処理
//	if( SetWindowIconID( MAINICON )) return -1;
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;		//描画先を裏画面に設定
	SetDrawMode(DX_DRAWMODE_BILINEAR);

	GameMain::Instance()->Initialize();

	while (LoopProcess()) {
		GameMain::Instance()->Update();
		GameMain::Instance()->Draw();
		if (!GameMain::Instance()->IsEnd())	break;
	}

	GameMain::Instance()->Finalize();
	DxLib_End();
	return 0;
}