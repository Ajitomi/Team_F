#pragma once

#include "AbstractScene.h";

#include "Dxlib.h"

#include "Image.h"

struct Sounds {
	int Select;
	int Move;
	int BGM;

	Sounds();
};

class GameOverScene :public AbstractScene
{

#define PI    3.1415926535897932384626433832795f

private:
	Image* bloodImages[3];		//血しぶき画像用変数
	float extend[3];			//血しぶきの拡大率

	Image* UIImages[3];			//文字画像

	Image* selecterImage;

	int selecter = 1;		//セレクター 1:タイトル　-1:終了

	int waitFrame = 0;			//2度押し防止用
	int cntFrame = 0;
	Sounds sounds;

public:
	GameOverScene();
	~GameOverScene();

	AbstractScene* Update() override;

	void Draw() const override;

	void selecterPos(int num);

	void End();
	void BloodSetPos();	//血しぶき用関数

	
};