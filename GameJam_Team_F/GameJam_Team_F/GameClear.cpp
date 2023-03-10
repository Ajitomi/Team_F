#include "DxLib.h"
#include "GameClear.h"
#include "SceneManager.h"
#include "KeyManager.h"
#include "Title.h"
#include <math.h>

GameClear::GameClear()
{
	g_ClearImage = LoadGraph("images/Clear/Certification1.jpg");           // Clear画像表示
	desk = LoadGraph("images/Clear/desk.jpg");           // 背景画像表示
	g_WaitTime = 0;//待ち時間
	g_PosY = 0;
}

AbstractScene* GameClear::Update()
{
	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	if (KeyManager::OnClick(KEY_INPUT_SPACE) && g_PosY <= 100)
	{
		return new Title();
	}

	return this;
}

void GameClear::Draw() const
{
	DrawGraph(0, 0, desk, FALSE);//背景画像(机)
	//タイトル画像表示
	DrawGraph(400, 0+ g_PosY, g_ClearImage, FALSE);//真ん中に行くようにする

	if (g_PosY <= 100)
	{
		DrawString(580, 600, "Pleas Space Key!", 0x000000);
	}
}