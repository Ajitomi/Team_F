#include "DxLib.h"
#include "Title.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "KeyManager.h"


Title::Title()
{
	//メニューの入力
	MenuNum = 0;
	MenuY = 0;
	KeyY = -1;
	flgY = 0;

	//色の入力
	Cr = GetColor(255, 0, 0);

	TitleLogoImage = LoadGraph("images/TitleLogo.png");
	TitleBGM = LoadSoundMem("music/morning_talk.wav"); //タイトルBGM
	StartSE = LoadSoundMem("music/StartSE.wav"); //ゲーム開始SE
	CarsolSE = LoadSoundMem("music/CarsolSE.wav"); //ゲーム開始SE
	(PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE));//タイトルBGM流す
}

AbstractScene* Title::Update()
{

	
	//ESCAPEキーで終了
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();

	//メニュー選択
	if (KeyManager::OnClick(KEY_INPUT_SPACE)) {
		switch (MenuNum)
		{
		case 0:
			StopSoundMem(TitleBGM);
			(PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, TRUE));//開始音
			return new GameMainScene();	//ゲーム画面へ
			break;

		}
	}

	return this;
}

void Title::Draw() const
{
	DrawString(520, 650, "--SPACE Click START--", Cr);
	DrawGraph(370, 100, TitleLogoImage, FALSE);
}