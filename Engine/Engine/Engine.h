#pragma once

#include "Core.h"

struct KeyState
{
	
	bool isKeyDown = false;

	bool wasKeyDown = false;

};

enum class CursorType
{
	Nocursor,
	SolidCursor,
	NormalCursor
};

class Engine

{
public :
	Engine();
	
	virtual ~Engine();

	void Run();

	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	void QuitGame();

protected:

	void ProcessInput();

	void Update();

	void Draw();

	void SavePreviouseKeyStates();

protected:

	float targetFrameRate = 60.0f;

	float targetOneFrameTime = 0.0f;

	bool quit = false;

	KeyState keyState[256];

	bool shouldUpdate = true;


private:
};