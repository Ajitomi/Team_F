#pragma once
#include"AbstractScene.h"

class GameClear:public AbstractScene
{
private:
	int g_ClearImage;
	int	g_WaitTime;			// �҂�����
    int g_PosY;					// �X�N���[�����̂x���W
public:
	GameClear();
	AbstractScene* Update() override;
	void Draw() const override;
};

