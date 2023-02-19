#include "DxLib.h"
#include "Title.h"
#include "SceneManager.h"
#include "GameMainScene.h"
#include "KeyManager.h"


Title::Title()
{
	//���j���[�̓���
	MenuNum = 0;
	MenuY = 0;
	KeyY = -1;
	flgY = 0;

	//�F�̓���
	Cr = GetColor(255, 0, 0);

	TitleLogoImage = LoadGraph("images/TitleLogo.png");
	TitleBGM = LoadSoundMem("music/morning_talk.wav"); //�^�C�g��BGM
	StartSE = LoadSoundMem("music/StartSE.wav"); //�Q�[���J�nSE
	CarsolSE = LoadSoundMem("music/CarsolSE.wav"); //�Q�[���J�nSE
	(PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE));//�^�C�g��BGM����
}

AbstractScene* Title::Update()
{

	
	//ESCAPE�L�[�ŏI��
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) DxLib_End();

	//���j���[�I��
	if (KeyManager::OnClick(KEY_INPUT_SPACE)) {
		switch (MenuNum)
		{
		case 0:
			StopSoundMem(TitleBGM);
			(PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, TRUE));//�J�n��
			return new GameMainScene();	//�Q�[����ʂ�
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