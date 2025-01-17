#pragma once

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
	Actor** actors;

	int capacity;

	int count;
};