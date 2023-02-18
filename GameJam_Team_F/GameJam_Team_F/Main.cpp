#include "DxLib.h"
#include "SceneManager.h"
#include "Title.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("****");

	ChangeWindowMode(TRUE);	//�E�B���h�E���[�h�ŋN��
	SetGraphMode(1280, 720, 32);	//�E�B���h�E�T�C�Y��ݒ�
	if (DxLib_Init() == -1)return -1;	//DX���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK);	//�`����ʂ𗠂�

	SceneManager scene_mng((AbstractScene*)new Title());

	//�Q�[�����[�v
	while ((ProcessMessage() == 0) && (scene_mng.Update() != nullptr))
	{

		ClearDrawScreen();	//��ʂ̏�����

		scene_mng.Draw();

		ScreenFlip();	//����ʂ̓��e��\��ʂɔ��f
	}

	return 0;
}