#include <PreCompiledHeader.h>

#include "Level.h"
#include "Actor/Actor.h"


Level::Level()
	: actors(nullptr), capacity(4), count(0)
{
	actors = new Actor * [capacity];

	memset(actors, 0, sizeof(size_t) * capacity);
}

Level::~Level()
{
	for (int ix = 0; ix < count; ++ix)
	{
		delete actors[ix];
	}

	delete[] actors;
}

void Level::AddActor(Actor* newActor)
{
}

void Level::Update()
{
}

void Level::Draw()
{
}
