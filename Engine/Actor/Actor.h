#pragma once

class Actor
{
public:
	Actor();

	virtual ~Actor();

	virtual void Update();
	virtual void Draw();

protected:
	bool isActive;
	bool isVisible;
	bool isExpired;
};