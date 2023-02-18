#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"SceneManager.h"


class Title:public AbstractScene
{
private:
	int MenuNum;
	
	//int TitleImage;
	int TitleLogoImage;
	int StartSE;
	int EndSE;
	int TitleBGM;

public:
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

};

