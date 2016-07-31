#include "GameMain.h"

GameMain::GameMain(){
	mSceneMgr.reset(new CSceneManager());
}


GameMain::~GameMain()
{
}

void GameMain::Initialize() {
	mSceneMgr->Init();
}

void GameMain::Update() {
	mSceneMgr->Update();
}

void GameMain::Draw() {
	mSceneMgr->Draw();
	mFps->Draw();
}

void GameMain::Finalize() {
}

bool GameMain::IsEnd() {
	if(mSceneMgr->IsEnd()) return false;
	return true;
}