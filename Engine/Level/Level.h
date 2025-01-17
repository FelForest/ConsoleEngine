#pragma once

#include "Container/List.h"

// 전방 선언
class Actor;
class Level
{
public:
	Level();

	virtual ~Level();

	void AddActor(Actor* newActor);

	virtual void Update();
	virtual void Draw();

protected:
	List<Actor*> actors;

	Actor* addRequestedActor = nullptr;
};