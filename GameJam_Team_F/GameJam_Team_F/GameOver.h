#pragma once

#include "AbstractScene.h";

#include "Dxlib.h"

#include "Image.h"

struct Sounds {
	int Select;
	int Move;
	int BGM;

	Sounds();
};

class GameOverScene :public AbstractScene
{

#define PI    3.1415926535897932384626433832795f

private:
	Image* bloodImages[3];		//�����Ԃ��摜�p�ϐ�
	float extend[3];			//�����Ԃ��̊g�嗦

	Image* UIImages[3];			//�����摜

	Image* selecterImage;

	int selecter = 1;		//�Z���N�^�[ 1:�^�C�g���@-1:�I��

	int waitFrame = 0;			//2�x�����h�~�p
	int cntFrame = 0;
	Sounds sounds;

public:
	GameOverScene();
	~GameOverScene();

	AbstractScene* Update() override;

	void Draw() const override;

	void selecterPos(int num);

	void End();
	void BloodSetPos();	//�����Ԃ��p�֐�

	
};