#pragma once
#include"DxLib.h"
#include "AbstractScene.h"

class SceneManager :public AbstractScene
{
private:
	AbstractScene* m_scene;

public:
	SceneManager(AbstractScene* scene) :m_scene(scene) {}

	~SceneManager() { delete m_scene; }

	AbstractScene* Update() override;

	void Draw() const override;
};