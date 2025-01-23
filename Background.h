#pragma once
#include <Novice.h>
class Background
{
public:
	int oneMapBack;
	int oneGameBack;
	Background()
	{
		oneMapBack= Novice::LoadTexture("./Resources/images/Background/mapScene.png");
		oneGameBack= Novice::LoadTexture("./Resources/images/Background/scene.png");
		
	}
};