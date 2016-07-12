#pragma once

#include <memory>

class GameMain
{
private:
	// シングルトンクラス
	GameMain();
	GameMain(const GameMain& gameMain) {}
	GameMain& operator=(const GameMain& gameMain) {}
	~GameMain();
public:
};

