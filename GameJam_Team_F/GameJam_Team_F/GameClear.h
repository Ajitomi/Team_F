#pragma once
#include"AbstractScene.h"

class GameClear:public AbstractScene
{
private:
	int g_ClearImage;
	int	g_WaitTime;			// 待ち時間
    int g_PosY;					// スクロール時のＹ座標
public:
	GameClear();
	AbstractScene* Update() override;
	void Draw() const override;
};

