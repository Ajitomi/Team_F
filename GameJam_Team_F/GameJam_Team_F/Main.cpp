#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("****");

	ChangeWindowMode(TRUE);	//ウィンドウモードで起動
	SetGraphMode(1280, 720, 32);	//ウィンドウサイズを設定
	if (DxLib_Init() == -1)return -1;	//DXライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK);	//描画先画面を裏に

	SceneManager scene_mng((AbstractScene*)new Title());

	//ゲームループ
	while ((ProcessMessage() == 0) && (scene_mng.Update() != nullptr))
	{

		ClearDrawScreen();	//画面の初期化

		scene_mng.Draw();

		ScreenFlip();	//裏画面の内容を表画面に反映
	}

	return 0;
}