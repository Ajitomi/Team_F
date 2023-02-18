#include "GameMain.h"
#include"DxLib.h"



AbstractScene* GameMain::Update() {

	return this;
}


void GameMain::Draw() const {

	DrawString(0, 0, "Main", 0xffffff,true);
}


GameMain::GameMain() {

}

GameMain::~GameMain() {

}
