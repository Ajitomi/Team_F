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


//�����w���\��
	DrawBox(350, 100, 650, 500, 0x553333, true);

//life�\��
	for (int i = 0; i < Life; i++)
	{
		//DrawCircle((i * 100) + 50, 50, 40, 0x997777, true);
		DrawGraph((i * 100) + 10, 10, LifeImage, true);
	}

//���\��

	DrawBox(750, 150, 1100, 350, 0x222222, true);
	DrawGraph(750, 150, QuestionBox, true);

//�I�����\��

	int MaxQuestion;		//��萔
	int QuestionPadding;	//�I�����Ԃ̋���
	int QuestioRange;		//�I�����̕�

	MaxQuestion = 4;
	QuestionPadding = 20;
	QuestioRange = ((1280 - 50) / MaxQuestion) - QuestionPadding;

	//550

	for (int i = 0; i < MaxQuestion; i++)
	{
		DrawBox((50 + (QuestioRange * i)) + (QuestionPadding * i), 550, ((50 + (QuestioRange * i)) + QuestioRange) + QuestionPadding * i, 650, 0x555555, true);
		DrawExtendGraph((50 + (QuestioRange * i)) + (QuestionPadding * i), 550, ((50 + (QuestioRange * i)) + QuestioRange) + QuestionPadding * i,650, PQuestionBox, true);
	}


//����ڂ��\��






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
	DrawFormatString(510, 430, GetColor(255, 255, 255), "��%d��", question_count);
}