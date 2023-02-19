#include "DxLib.h"
#include "GameClear.h"
#include "SceneManager.h"
#include <math.h>

GameClear::GameClear()
{
	g_ClearImage = LoadGraph("images/Clear/Certification1.png");           // Clear�摜�\��
	g_WaitTime = 0;//�҂�����
	g_PosY = 0;
}

AbstractScene* GameClear::Update()
{
	if (++g_WaitTime < 600) g_PosY = 300 - g_WaitTime / 2;

	return this;
}

void GameClear::Draw() const
{
	//�^�C�g���摜�\��
	DrawGraph(400, 0+ g_PosY, g_ClearImage, FALSE);//�^�񒆂ɍs���悤�ɂ���
}