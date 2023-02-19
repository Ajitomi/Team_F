#include "GameMainScene.h"
#include "DxLib.h"
#include "KeyManager.h"

int wait_time = 0;

GameMainScene::GameMainScene()
{
	

	LifeImage = LoadGraph("Image/life.png");
	QuestionBox = LoadGraph("Image/QuestionBox.png");
	PQuestionBox = LoadGraph("Image/PQuestionBox.png");
	LoadDivGraph("Image/MenheraMap.png",4,4,1,100,100, MenheraImage);

	MenheraCount = 0;
	MaxWink = 120;

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
	if (MenheraCount++ >= MaxWink) {
		MenheraCount = 0;
	}

	if (MenheraCount <=6) {
		MImage = 0;
	}
	else if (MenheraCount <= 10) {
		MImage = 1;
	}
	else if (MenheraCount <= 15) {
		MImage = 2;
	}
	else if (MenheraCount <= 24) {
		MImage = 3;
	}
	else if (MenheraCount <= 30) {
		MImage = 2;
	}
	else if (MenheraCount <= 36) {
		MImage = 1;
	}
	else if(MenheraCount <=120){
		MImage = 0;
		MaxWink = rand() % 200 + 120;
	}

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

//メンヘラ
	//DrawBox(350, 100, 650, 500, 0x553333, true);
	int ImageXX = 400;
	
	DrawExtendGraph(350, 100, 350 + ImageXX, 100 + ImageXX, MenheraImage[MImage], true);

//life表示
	for (int i = 0; i < life; i++)
	{
		//DrawCircle((i * 100) + 50, 50, 40, 0x997777, true);
		DrawGraph((i * 100) + 10, 10, LifeImage, true);
	}

//問題枠

	DrawBox(750, 150, 1100, 350, 0x222222, true);
	DrawGraph(750, 150, QuestionBox, true);

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
		DrawExtendGraph((50 + (QuestioRange * i)) + (i * QuestionPadding+ (QuestionPadding/2)), 550,
						((50 + (QuestioRange * i)) + QuestioRange) + (i * QuestionPadding + (QuestionPadding / 2)), 650, PQuestionBox, true);
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