#include "SceneManager.h"
#include "KeyManager.h"

AbstractScene* SceneManager::Update()
{
	// キー入力の更新
	KeyManager::Update();

	AbstractScene* p = m_scene->Update();
	if (p != m_scene)
	{
		delete m_scene;
		m_scene = p;
	}
	return p;
}

void SceneManager::Draw() const
{
	m_scene->Draw();
}