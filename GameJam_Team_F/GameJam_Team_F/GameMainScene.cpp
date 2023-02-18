#include "GameMainScene.h"
#include"DxLib.h"

AbstractScene* GameMainScene::Update()
{

	return this;
}

void GameMainScene::Draw() const
{
	//1280, 720
	DrawBox(0, 0, 1280, 720, 0x200303, true);
	DrawBox(0, 0, 1280, 720, 0x090909, true);



	for (int i = 0; i < 1280; i+=50)
	{
		DrawLine(i, 0, i, 720, 0x555522, true);
		DrawLine(0, i, 1280, i, 0x335533, true);
		if (i % 100 == 0) {
			DrawLine(i, 0, i, 720, 0x770000, true);
			DrawLine(0, i, 1280, i, 0x770000, true);
		}
	}

	DrawLine(1280 / 2, 0, 1280 / 2, 720, 0x008800, true);
	DrawLine(0, 720 / 2, 1280, 720 / 2, 0x888800, true);


//メンヘラ表示
	DrawBox(350, 100, 650, 500, 0x553333, true);

//life表示
	for (int i = 0; i < Life; i++)
	{
		//DrawCircle((i * 100) + 50, 50, 40, 0x997777, true);
		DrawGraph((i * 100) + 10, 10, LifeImage, true);
	}

//問題表示

	DrawBox(750, 150, 1100, 350, 0x222222, true);
	DrawGraph(750, 150, QuestionBox, true);

//選択肢表示

	int MaxQuestion;		//問題数
	int QuestionPadding;	//選択肢間の距離
	int QuestioRange;		//選択肢の幅

	MaxQuestion = 4;
	QuestionPadding = 20;
	QuestioRange = ((1280 - 50) / MaxQuestion) - QuestionPadding;

	//550

	for (int i = 0; i < MaxQuestion; i++)
	{
		DrawBox((50 + (QuestioRange * i)) + (QuestionPadding * i), 550, ((50 + (QuestioRange * i)) + QuestioRange) + QuestionPadding * i, 650, 0x555555, true);
		DrawExtendGraph((50 + (QuestioRange * i)) + (QuestionPadding * i), 550, ((50 + (QuestioRange * i)) + QuestioRange) + QuestionPadding * i,650, PQuestionBox, true);
	}


//何問目か表示






}