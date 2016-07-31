#pragma once
#include "sceneManager.h"
#include "FPS.h"

#include <memory>

class GameMain
{
private:
	// �V���O���g���N���X
	GameMain();
	GameMain(const GameMain& gameMain) {}
	GameMain& operator=(const GameMain& gameMain) {}
	~GameMain();

	std::unique_ptr<FPS> mFps;
	std::unique_ptr<CSceneManager> mSceneMgr;

public:
	// �C���X�^���X�ɃA�N�Z�X
	static GameMain* Instance() {
		static GameMain inst;
		return &inst;
	}

	void Initialize();
	void Update();
	void Draw();
	void Finalize();
	bool IsEnd();
};

