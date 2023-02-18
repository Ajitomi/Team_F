#include "DxLib.h"
#include "Title.h"
#include "SceneManager.h"


Title::Title()
{
	//���j���[�̓���
	MenuNum = 0;
	TitleLogoImage = LoadGraph("images/TitleLogo.png");
	TitleBGM = LoadSoundMem("music/morning_talk.wav"); //�^�C�g��BGM
	StartSE = LoadSoundMem("music/StartSE.wav"); //�Q�[���J�nSE
	EndSE = LoadSoundMem("music/EndSE.wav"); //�Q�[���I��SE
	(PlaySoundMem(TitleBGM, DX_PLAYTYPE_LOOP, TRUE));//�^�C�g��BGM����
}

AbstractScene* Title::Update()
{
	////���j���[�I��
	// 	   StopSoundMem(TitleBGM);
	//(PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, TRUE));//���艹
	//if (KeyManager::OnClick(KEY_INPUT_SPACE)) {
	//	switch (MenuNum)
	//	{
	//	case 0:
	//		return new Main();	//�Q�[����ʂ�
	//		break;

	//	}
	//}

	return this;
}

void Title::Draw() const
{
	DrawGraph(640, 50, TitleLogoImage, FALSE);
}