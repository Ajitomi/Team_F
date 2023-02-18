#pragma once

#include "AbstractScene.h"
#include"DxLib.h"

class GameMainScene :public AbstractScene
{
private:
	int Life;
	int Cnt_Question;

	int LifeImage;
	int QuestionBox;
	int PQuestionBox;


public:
	GameMainScene() {
		Life = 3;
		Cnt_Question = 0;

		LifeImage = LoadGraph("Image/life.png");
		QuestionBox = LoadGraph("Image/QuestionBox.png");
		PQuestionBox = LoadGraph("Image/PQuestionBox.png");
		
	};
	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw() const;
};