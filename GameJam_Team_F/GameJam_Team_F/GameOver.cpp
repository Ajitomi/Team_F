#include "GameOver.h"
#include "Title.h"

//コンストラクタ
GameOverScene::GameOverScene(){
	bloodImages[0] = new Image("Image/OverImages/blood_1.png");
	bloodImages[1] = new Image("Image/OverImages/blood_2.png");
	bloodImages[2] = new Image("Image/OverImages/blood_3.png");
	BloodSetPos();

	UIImages[0] = new Image("Image/OverImages/GameOver.png",0,100);
	UIImages[1] = new Image("Image/OverImages/Title.png", 440, 400,840,480);
	UIImages[2] = new Image("Image/OverImages/End.png", 440, 500, 840, 580);

	selecterImage = new Image("Image/OverImages/blood_1.png",420,550);
	selecterPos(selecter);

	sounds = Sounds();
	PlaySoundMem(sounds.BGM, DX_PLAYTYPE_LOOP);
}

//デストラクタ
GameOverScene::~GameOverScene() {

}


AbstractScene* GameOverScene::Update()
{

	//矢印上下キー
	if (CheckHitKey(KEY_INPUT_UP) != 0 || CheckHitKey(KEY_INPUT_DOWN) != 0) {
		if (waitFrame <= 0) {
			PlaySoundMem(sounds.Move, DX_PLAYTYPE_BACK);
			selecter *= -1;
			selecterPos(selecter);
			waitFrame = 10;
		}
		else {
			if (--waitFrame < 0) {
				waitFrame = 0;
			}
		}
	}
	else {
		waitFrame = 0;
	}

	if (++cntFrame > 30) cntFrame = 30;

	if (CheckHitKey(KEY_INPUT_RETURN) != 0) {
		if (selecter == 1) {
			PlaySoundMem(sounds.Select, DX_PLAYTYPE_BACK);
			WaitTimer(1000);

			StopSoundMem(sounds.BGM);
			//タイトルへ
			return new Title();
		}
		else {
			//終了
			End();
		}
	}
	return this;
}

void GameOverScene::Draw() const{

	SetDrawBright(255, 255, 255);
	DrawGraph((int)UIImages[0]->posx, (int)UIImages[0]->posy,
					UIImages[0]->image, true);

	if (selecter == 1) {
		SetDrawBright(255, 0, 0);
	}
	else {
		SetDrawBright(255, 255, 255);
	}
	DrawExtendGraph((int)UIImages[1]->posx, (int)UIImages[1]->posy,
					(int)UIImages[1]->width, (int)UIImages[1]->hight,
					UIImages[1]->image, true); 


	if (selecter == -1) {
		SetDrawBright(255, 0, 0);
	}
	else {
		SetDrawBright(255, 255, 255);
	}
	DrawExtendGraph((int)UIImages[2]->posx, (int)UIImages[2]->posy,
					(int)UIImages[2]->width, (int)UIImages[2]->hight,
					UIImages[2]->image, true);


	DrawRotaGraph((int)selecterImage->posx, (int)selecterImage->posy,
					0.5f,0,
				selecterImage->image, true);

	for (int i = 0; i < (sizeof(bloodImages) / sizeof(*bloodImages)); i++) {
		DrawRotaGraph((int)bloodImages[i]->posx, (int)bloodImages[i]->posy,
			(extend[i] / 30) * cntFrame, 0,
			bloodImages[i]->image, true);
	}

}

void GameOverScene::End() {
	DxLib_End();
}

void GameOverScene::BloodSetPos() {

	DATEDATA Date;
	// 現在時刻を得る
	GetDateTime(&Date);

	SRand(Date.Sec);
	for (int i = 0; i < (sizeof(bloodImages) / sizeof(*bloodImages)); i++) {

		float randPosX, randPosY;
		randPosX = float(GetRand(100) + ((cos(GetRand(100) % 2 * PI) * 300) + 540));

		randPosY = float(GetRand(360) + 360);

		bloodImages[i]->SetSize(randPosX, randPosY);

		extend[i] = float(GetRand(200) + 50) / 100;
	}
}

void GameOverScene::selecterPos(int num) {
	float x = 480, y = 500;

	selecterImage->SetSize(x, (y + 50 * -selecter));
}

Sounds::Sounds() {
	Select = LoadSoundMem("Sounds/over/select.mp3");
	Move = LoadSoundMem("Sounds/over/move.mp3");
	BGM = LoadSoundMem("Sounds/over/MusicBox_07.mp3");
}
