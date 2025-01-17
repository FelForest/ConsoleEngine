#pragma once

#include <RTTI.h>
#include "Math/Vector2.h"

class Actor : public RTTI
{
public:
	Actor();

	virtual ~Actor();

	virtual void Update();
	virtual void Draw();

	virtual void SetPosition(const Vector2& newPosition);
	inline Vector2 Position() const;

	inline bool IsActive() const { return isActive && !isExpired; }
	inline void SetActive(bool active) { isActive = active; }
	inline void Destroy() { isExpired = true; }


protected:
	Vector2 position;

	bool isActive;
	bool isVisible;
	bool isExpired;
};