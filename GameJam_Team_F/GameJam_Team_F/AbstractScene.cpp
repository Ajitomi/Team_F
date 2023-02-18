#include "SceneManager.h"

AbstractScene* SceneManager::Update()
{
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