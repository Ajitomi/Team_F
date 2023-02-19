#pragma once

#include "AbstractScene.h"
#include "DxLib.h"
#include "KeyManager.h"

class GameMainScene :public AbstractScene
{
private:
	
	int LifeImage;
	int QuestionBox;
	int PQuestionBox;

	struct Question
	{
		int number;				//���̃i���o�[
		char sentence[100];		//��蕶
		int correct;			//�����̃{�^���ԍ�
		char answer_1[100];
		char answer_2[100];
		char answer_3[100];
	};

	int life;					//HP

	int question_number;		//���݂̖��i���o�[	
	int question_count;			//���݂̖�萔���J�E���g

	int answer_namber;			//�񓚔ԍ�

	int correct_answers;		//����

	bool question_flag;			//���������Ă�Œ������肷��t���O

	Question question[16];		//�S21��

public:

	GameMainScene();

	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};