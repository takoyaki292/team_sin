#pragma once
#include <Novice.h>
class Background
{
public:
	int oneMapBack;
	int oneGameBack;
	int skillBack;
	Background()
	{
		oneMapBack= Novice::LoadTexture("./Resources/images/Background/mapScene.png");
		oneGameBack= Novice::LoadTexture("./Resources/images/Background/scene.png");
		skillBack= Novice::LoadTexture("./Resources/images/Background/skill.jpg");
	}
};