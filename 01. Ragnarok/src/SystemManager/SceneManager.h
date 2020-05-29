#pragma once
#include "Game/GameScene/Scene.h"

class SceneManager {
public:
	bool init();
	void release();

public:
	void update(float deltaTime);
	void render(HDC hdc);
	void afterRender(HDC hdc);
	void debugRender(HDC hdc);

public:
	class Scene* addScene(std::string sceneName, Scene* scene);
	bool changeScene(std::string sceneName);
	Scene* getCurScene() { return _currentScene; }
	bool scenePush(std::string sceneName);
	bool scenePop();

private:
	typedef std::map<std::string, Scene*> mScenevector;
	typedef std::map<std::string, Scene*>::iterator miScenevector;

private:
	Scene* _currentScene = nullptr;
	mScenevector _mScenevector;
	std::stack<Scene*> sceneStack;

private:
	DECLARE_SINGLE(SceneManager)
};

#define SCENEMANAGER SceneManager::GetInst()