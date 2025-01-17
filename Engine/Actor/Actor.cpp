#include "Actor.h"

Actor::Actor()
	: isActive(true), isVisible(true), isExpired(false)
{
}

Actor::~Actor()
{
}

void Actor::Update()
{
}

void Actor::Draw()
{
}

void Actor::SetPosition(const Vector2& newPosition)
{
	position = newPosition;	
}

inline Vector2 Actor::Position() const
{
	return position;
}
