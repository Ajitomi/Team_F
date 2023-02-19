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
	int MenheraImage[4];
	int MImage;
	int MenheraCount;
	int MaxWink;

	struct Question
	{
		int number;				//���̃i���o�[
		char sentence[100];		//��蕶
		int correct;			//�����̃{�^���ԍ�
		char answer_1[50];
		char answer_2[50];
		char answer_3[50];
	};

	int life;					//HP

	int question_number;		//���݂̖��i���o�[	
	int question_count;			//���݂̖�萔���J�E���g

	int answer_namber;			//�񓚔ԍ�

	int correct_answers;		//����

	bool question_flag;			//���������Ă�Œ������肷��t���O

	Question question[21];		//�S21��

public:

	GameMainScene();

	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};