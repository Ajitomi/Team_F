#pragma once

#include "AbstractScene.h"

class GameMainScene :public AbstractScene
{
private:
	int Life;
	int Cnt_Question;
public:
	GameMainScene() {};
	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw() const;
};