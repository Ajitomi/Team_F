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

	bool question_flag;

	Question question[21];

	GameMainScene();
	
	/*		
	GameMainScene() {
		Life = 3;
		Cnt_Question = 0;

		LifeImage = LoadGraph("Image/life.png");
		QuestionBox = LoadGraph("Image/QuestionBox.png");
		PQuestionBox = LoadGraph("Image/PQuestionBox.png");
		
	};
	*/


	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};