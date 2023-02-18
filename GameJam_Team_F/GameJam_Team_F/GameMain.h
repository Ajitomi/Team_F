#pragma once
#include "AbstractScene.h"
class GameMain : public AbstractScene
{
private:
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;



public:
	GameMain();
	~GameMain();


};

