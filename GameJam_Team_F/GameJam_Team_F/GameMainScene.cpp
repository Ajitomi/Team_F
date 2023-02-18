#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"

int wait_time = 0;

GameMainScene::GameMainScene()
{

	life = 3;

	question_number = 0;
	question_count = 1;

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

	wait_time++;

	if (question_flag == false && wait_time >= 600)
	{
		question_flag = true;
		wait_time = 0;
		question_number = GetRand(21);
	}

	if (KeyManager::OnClick(KEY_INPUT_A))
	{
		wait_time = 0;
		question_flag = false;
	}

	if (question_count >= 7 && life > 0)
	{
		//GameClear
	}

	if (life < 0)
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
#endif

	DrawFormatString(510, 450, GetColor(255, 255, 255), "%s", question[question_number].sentence);
	DrawFormatString(510, 430, GetColor(255, 255, 255), "‘æ%d–å", question_count);
}