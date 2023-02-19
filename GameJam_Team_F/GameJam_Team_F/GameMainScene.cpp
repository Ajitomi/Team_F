#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"

int wait_time = 0;

GameMainScene::GameMainScene()
{

	life = 3;

	question_number = 0;
	question_count = 1;

	answer_namber = 0;

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

			sscanf_s(line, "%d,%d,%s",
				&question[i].number,
				&question[i].correct,
				question[i].sentence, 100);
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
		answer_namber = 0;
		question_flag = false;
	}
	else if (answer_namber != 0 && answer_namber != question[question_number].correct)
	{
		life--;
		question_count++;
		answer_namber = 0;
		question_flag = false;
	}

	if (question_count > 7 && life > 0)
	{
		//GameClear
	}

	if (life <= 0)
	{
		//GameOver
	}

	return this;
}

void GameMainScene::Draw() const
{

#ifdef _DEBUG
	/*for (int i = 0; i < 21; i++)
	{
		DrawFormatString(0, 20 * i, GetColor(255, 255, 255), "QuestionNumber = %d", question[i].number);
		DrawFormatString(190, 20 * i, GetColor(255, 255, 255), "QuestionSentence = %s", question[i].sentence);
	}*/
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Life = %d", life);
	DrawFormatString(150, 0, GetColor(255, 255, 255), "Number = %d", question_number);
	DrawFormatString(300, 0, GetColor(255, 255, 255), "Correct = %d", question[question_number].correct);
	DrawFormatString(450, 0, GetColor(255, 255, 255), "Correct = %d", question_flag);
#endif

	DrawFormatString(510, 450, GetColor(255, 255, 255), "%s", question[question_number].sentence);
	DrawFormatString(510, 430, GetColor(255, 255, 255), "‘æ%d–å", question_count);
}