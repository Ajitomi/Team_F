#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"
#include"GameClear.h"

int wait_time = 0;

GameMainScene::GameMainScene()
{
	
	LifeImage = LoadGraph("Image/life.png");
	QuestionBox = LoadGraph("Image/QuestionBox.png");
	PQuestionBox = LoadGraph("Image/PQuestionBox.png");


	life = 3;

	question_number = 0;
	question_count = 1;

	answer_namber = 0;

	correct_answers = 0;

	question_flag = false;

	FILE* fp;
	errno_t error;
	error = fopen_s(&fp, "Data/Question_Data.csv", "r");

	if (error != 0)
	{

		return;
	}
	else
	{
		char line[1000];

		for (int i = 0; fgets(line, 1000, fp) != NULL; i++)
		{

			sscanf_s(line, "%d,%d,%[^,],%[^,],%[^,],%[^,]",
				&question[i].number,
				&question[i].correct,
				question[i].sentence, 100,
				question[i].answer_1, 50,
				question[i].answer_2, 50,
				question[i].answer_3, 50);
		}

		return;
	}
	fclose(fp);

}


AbstractScene* GameMainScene::Update()
{

	if (question_flag == false)
	{
		question_number = GetRand(20);
		question_flag = true;
	}

	if (KeyManager::OnClick(KEY_INPUT_1) && question_flag == true)
	{
		answer_namber = 1;
	}
	else if (KeyManager::OnClick(KEY_INPUT_2) && question_flag == true)
	{
		answer_namber = 2;
	}
	else if (KeyManager::OnClick(KEY_INPUT_3) && question_flag == true)
	{
		answer_namber = 3;
	}
	else if (KeyManager::OnClick(KEY_INPUT_4) && question_flag == true)
	{
		answer_namber = 4;
	}

	if (answer_namber == question[question_number].correct)
	{
		question_count++;
		correct_answers++;
		answer_namber = 0;
		question_flag = false;
	}
	else if (answer_namber != 0 && answer_namber != question[question_number].correct)
	{
		/*life--;*/
		question_count++;
		answer_namber = 0;
		question_flag = false;
	}

	if (question_count > 7 && life > 0)
	{
		//GameClear
		return new GameClear();
	}

	if (life <= 0)
	{
		//GameOver
	}

	return this;
}

void GameMainScene::Draw() const
{

//背景
	DrawBox(350, 100, 650, 500, 0x553333, true);

//life表示
	for (int i = 0; i < life; i++)
	{
		//DrawCircle((i * 100) + 50, 50, 40, 0x997777, true);
		DrawGraph((i * 100) + 10, 10, LifeImage, true);
	}

//問題枠

	DrawBox(750, 150, 1200, 350, 0x222222, true);
	//DrawGraph(750, 150, QuestionBox, true);
	DrawExtendGraph(750, 150, 1200, 350, QuestionBox, true);

//選択肢枠

	int MaxQuestion;		//選択しの数
	int QuestionPadding;	//選択肢の隙間
	int QuestioRange;		//選択肢の幅

	MaxQuestion = 4;
	QuestionPadding = 20;
	QuestioRange = ((1280 - 100) / MaxQuestion) - QuestionPadding;



	for (int i = 0; i < MaxQuestion; i++)
	{
		DrawBox((50 + (QuestioRange * i)) + (QuestionPadding * i + (QuestionPadding / 2)), 550,
				((50 + (QuestioRange * i)) + QuestioRange) + QuestionPadding * i + (QuestionPadding / 2), 650, 0x555555, true);

		DrawExtendGraph((50 + (QuestioRange * i)) + (i * QuestionPadding + (QuestionPadding / 2)), 550,
				((50 + (QuestioRange * i)) + QuestioRange) + (i * QuestionPadding + (QuestionPadding / 2)), 650, PQuestionBox, true);
	}

#ifdef _DEBUG
	//for (int i = 0; i < 21; i++)
	//{
	//	/*DrawFormatString(0, 20 * i, GetColor(255, 255, 255), "QuestionNumber = %d", question[i].number);*/
	//	DrawFormatString(0, 20 * i, GetColor(255, 255, 255), "QuestionSentence = %s", question[i].sentence);
	//	DrawFormatString(580, 20 * i, GetColor(255, 255, 255), "Answer_1Sentence = %s", question[i].answer_1);
	//	DrawFormatString(900, 20 * i, GetColor(255, 255, 255), "QuestionSentence = %s", question[i].answer_2);
	//}
	/*DrawFormatString(0, 0, GetColor(255, 255, 255), "Life = %d", life);
	DrawFormatString(150, 0, GetColor(255, 255, 255), "Number = %d", question_number);
	DrawFormatString(300, 0, GetColor(255, 255, 255), "Correct = %d", question[question_number].correct);
	DrawFormatString(450, 0, GetColor(255, 255, 255), "flag = %d", question_flag);*/
#endif

	/*SetFontSize(25);*/
	DrawFormatString(770, 170, GetColor(255, 255, 255), "第%d門", question_count);
	DrawFormatString(770, 250, 0xFFFFFF, "%s", question[question_number].sentence);

	DrawFormatString((100 + (QuestioRange * 0)) + (QuestionPadding * 0 + (QuestionPadding / 2)), 595, 0xFFFFFF, "%s", question[question_number].answer_1);
	DrawFormatString((100 + (QuestioRange * 1)) + (QuestionPadding * 1 + (QuestionPadding / 2)), 595, 0xFFFFFF, "%s", question[question_number].answer_2);
	DrawFormatString((100 + (QuestioRange * 2)) + (QuestionPadding * 2 + (QuestionPadding / 2)), 595, 0xFFFFFF, "%s", question[question_number].answer_3);
	//DrawFormatString((100 + (QuestioRange * 3)) + (QuestionPadding * 3 + (QuestionPadding / 2)), 595, 0xFFFFFF, "%s", question[question_number].answer_1);
}