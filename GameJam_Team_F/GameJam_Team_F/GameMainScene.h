#pragma once

#include "AbstractScene.h"
#include "KeyManager.h"

class GameMainScene :public AbstractScene
{
private:

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

public:

	GameMainScene();
	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;
};