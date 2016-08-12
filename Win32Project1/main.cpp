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

// �v���O������WinMain����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (SetGraphMode(
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		16
	) != DX_CHANGESCREEN_OK) return -1;	// �E�B���h�E�T�C�Y��ύX����
	if (ChangeWindowMode(TRUE) != DX_CHANGESCREEN_OK) return -1; //�E�B���h�E���Ə���������
//	if( SetWindowIconID( MAINICON )) return -1;
	if (DxLib_Init() == -1 || SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;		//�`���𗠉�ʂɐݒ�
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