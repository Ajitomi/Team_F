#pragma once
#include"DxLib.h"
#include"AbstractScene.h"
#include"SceneManager.h"


class Title:public AbstractScene
{
private:
	int MenuNum;
	int MenuY;
	int KeyY;
	int flgY;
	int Cr;
	
	//int TitleImage;
	int TitleLogoImage;
	int StartSE;
	int CarsolSE;
	int TitleBGM;

public:
	Title();
	virtual ~Title() {};
	virtual AbstractScene* Update() override;
	virtual void Draw() const override;

};



