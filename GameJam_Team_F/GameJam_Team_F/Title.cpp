#include "DxLib.h"
#include "Title.h"
#include "SceneManager.h"


Title::Title()
{
	//メニューの入力
	MenuNum = 0;
	TitleLogoImage = LoadGraph("images/TitleLogo.png");
	TitleBGM = LoadSoundMem("music/morning_talk.wav"); //タイトルBGM
	StartSE = LoadSoundMem("music/StartSE.wav"); //ゲーム開始SE
	EndSE = LoadSoundMem("music/EndSE.wav"); //ゲーム終了SE
	(PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE));//タイトルBGM流す
}

AbstractScene* Title::Update()
{
	////メニュー選択
	// 	   StopSoundMem(TitleBGM);
	//(PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, TRUE));//決定音
	//if (KeyManager::OnClick(KEY_INPUT_SPACE)) {
	//	switch (MenuNum)
	//	{
	//	case 0:
	//		return new Main();	//ゲーム画面へ
	//		break;

	//	}
	//}

	return this;
}

void Title::Draw() const
{
	DrawGraph(640, 50, TitleLogoImage, FALSE);
}