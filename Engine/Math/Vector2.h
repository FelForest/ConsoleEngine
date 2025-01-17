#pragma once

#include <PreCompiledHeader.h>

class Vector2
{
public:
	
	Vector2(int x = 0, int y = 0);
	~Vector2() = default;

	// 연산자 오버로딩 
	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	// 내적
	int dot(const Vector2& other) const;
public:
	int x = 0;
	int y = 0;
};