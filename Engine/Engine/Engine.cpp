#include <PreCompiledHeader.h>

#include "Engine.h"

Engine::Engine()
    : quit(false)
{

}

Engine::~Engine()
{
}

void Engine::Run()
{
    // Cpu 시계 사용
    _LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);

    // 시작 시간 및 이전 시간을 위한 변수
    LARGE_INTEGER time;
    QueryPerformanceCounter(&time);

    int64_t currentTime = time.QuadPart;
    int64_t previousTime = 0;

    // 프레임 제한 FPS 그거
    // Todo: 프레임 조절 가능하세 변경
    float targetFrameRate = 60.0f;

    // 한 프레임당 시간
    float targetOneFrameTime = 1.0f / targetFrameRate;

    // Game-Loop
    while (true)
    {
        if (quit)
        {
            break;
        }

        QueryPerformanceCounter(&time);
        currentTime = time.QuadPart;

        // 프레임 시간
        float deltaTime = static_cast<float>(currentTime - previousTime) / static_cast<float>(frequency.QuadPart);

        if (deltaTime >= targetOneFrameTime)
        {
            ProcessInput();

            Update();

            Draw();

            SavePreviouseKeyStates();

            previousTime = currentTime;
        }
    }
}

bool Engine::GetKey(int key)
{
    return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
    return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
    return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
    quit = true;
}

// 입력 처리
void Engine::ProcessInput()
{
    for (int ix = 0; ix < 256; ++ix)
    {
        keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
    }
}

void Engine::Update()
{

}

void Engine::Draw()
{
}

void Engine::SavePreviouseKeyStates()
{
    for (int ix = 0; ix < 255; ++ix)
    {
        keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
    }
}
