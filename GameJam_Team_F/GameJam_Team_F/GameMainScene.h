#pragma once

#include "AbstractScene.h"

class GameMainScene :public AbstractScene
{
private:

public:
	GameMainScene() {};
	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw() const;
};