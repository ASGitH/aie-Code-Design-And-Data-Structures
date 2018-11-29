#include "raylib.h"
#include "tVector.h"
#pragma once

class player {
public:
	// What would I need to make a player?
	player();
	~player();

	Texture2D texture;
	Rectangle playerRectangleObject;
	Vector2 position;
	Vector2 spawnPosition;

	int speed;
	void update(float deltaTime);
	void draw();
};