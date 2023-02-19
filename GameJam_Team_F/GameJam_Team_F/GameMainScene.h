#pragma once

#include "AbstractScene.h"
#include "DxLib.h"
#include "KeyManager.h"

class GameMainScene :public AbstractScene
{
private:
	
	int LifeImage;
	int QuestionBox;
	int PQuestionBox;
	int MenheraImage[4];
	int MImage;
	int MenheraCount;
	int MaxWink;

	struct Question
	{
		int number;				//問題のナンバー
		char sentence[100];		//問題文
		int correct;			//正解のボタン番号
		char answer_1[50];
		char answer_2[50];
		char answer_3[50];
	};

	int life;					//HP

	int question_number;		//現在の問題ナンバー	
	int question_count;			//現在の問題数をカウント

	int answer_namber;			//回答番号

	int correct_answers;		//正解数

	bool question_flag;			//問題を解いてる最中か判定するフラグ

	Question question[21];		//全21門

public:

	GameMainScene();

	~GameMainScene() {};

	virtual AbstractScene* Update();

	virtual void  Draw()const;


};