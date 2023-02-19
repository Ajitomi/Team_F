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

	int answer_namber;

	bool question_flag;

	Question question[21];

	GameMainScene();
	



	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};