#pragma once

#include "AbstractScene.h"
#include"DxLib.h"
#include "KeyManager.h"


class GameMainScene :public AbstractScene
{
private:
	int Life;
	int Cnt_Question;

	int LifeImage;
	int QuestionBox;
	int PQuestionBox;
	int MenheraImage[4];
	int MImage;
	int MenheraCount;
	int MaxWink;



	


public:


	struct Question
	{
		int number;
		char sentence[100];
		int correct;
	};

	int life;

	int question_number;
	int question_count;

	bool question_flag;

	Question question[21];

	GameMainScene();
	



	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};