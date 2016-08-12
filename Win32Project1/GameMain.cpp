#include "GameMain.h"

GameMain::GameMain(){
	mFps.reset(new FPS());
	mInput.reset(new Input());
	mSceneMgr.reset(new CSceneManager());
}


GameMain::~GameMain()
{
}

void GameMain::Initialize() {
	mSceneMgr->Init();
}

void GameMain::Update() {
	mSceneMgr->Update(mInput);
	mFps->Wait();
}

void GameMain::Draw() {
	mSceneMgr->Draw();
	mFps->Draw();
}

void GameMain::Finalize() {
}

bool GameMain::IsEnd() {
	if (mInput->All()) return false;
	if (mSceneMgr->IsEnd()) return false;
	return true;
}