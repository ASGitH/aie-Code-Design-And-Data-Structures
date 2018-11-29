#include "gameState.h"
#include "main_Menu.h"
#include "raylib.h"
#include "tStack.h"

tStack<int> menuStackObject;

mainMenu::mainMenu()
{
	SetWindowSize(1000, 425);
	menuStackObject.push(1);

	std::cout << "Size: " << menuStackObject.size() << std::endl;
	std::cout << "Top: " << menuStackObject.top();
	std::cout << std::endl;

	if (menuStackObject.top() == 1 && GameState::GetInstance().getState() == 0) {
		mainMenuTexture = LoadTexture("PNG/blue_button00.png");
		buttonTexture = LoadTexture("PNG/blue_button13.png");
	}
}

mainMenu::~mainMenu()
{
	UnloadTexture(mainMenuTexture);
	UnloadTexture(buttonTexture);
}

void mainMenu::draw(float width, float height)
{
	if (menuStackObject.top() == 1) {
		// --- Buttons --- //
		DrawTextureEx(mainMenuTexture, { 0.0f, 0.0f }, 0.0f, 5.26f, WHITE);
		// Start Button
		DrawTextureEx(buttonTexture, { 0.0f, height * 4.75f }, 0.0f, 2.625f, WHITE);
		// Exit Button
		DrawTextureEx(buttonTexture, { 500.25f, height * 4.75f }, 0.0f, 2.625f, WHITE);

		// --- Text --- //
		// Title Text
		DrawText("Place_Holder_The_Game_That_Never_Came_To_Be", width * .1f, height * 1.625f, 38.0f, BLACK);
		// Start Text
		DrawText("Start", width * 0.75f, height * 5.375f, 50.0f, BLACK);
		// Exit Text
		DrawText("Exit", width * 2.75f, height * 5.375f, 50.0f, BLACK);
	}
}

void mainMenu::update(float deltaTime)
{
	if (menuStackObject.top() == 1 && GameState::GetInstance().getState() == 0) {
		// Make three buttons
		Rectangle buttonRectangleObject[3];

		for (int i = 0; i < 2; i++) {
			// Start Button
			if (i == 0) {
				buttonRectangleObject[i].x = 0;
				buttonRectangleObject[i].y = 300;
				buttonRectangleObject[i].width = 500;
				buttonRectangleObject[i].height = 125;
			}
			// Exit Button
			if (i == 1) {
				buttonRectangleObject[i].x = 500;
				buttonRectangleObject[i].y = 300;
				buttonRectangleObject[i].width = 500;
				buttonRectangleObject[i].height = 125;
			}
		}
		mousePoint = GetMousePosition();

		// Check collision between the mouse and the buttons
		for (int i = 0; i < 2; i++) {

			// Start Menu
			if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[0]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				menuStackObject.push(2);

				std::cout << "Size: " << menuStackObject.size() << std::endl;
				std::cout << "Top: " << menuStackObject.top();
				std::cout << std::endl;

				GameState::GetInstance().setState(1);
			}

			// Exit
			if (CheckCollisionPointRec(mousePoint, buttonRectangleObject[1]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				GameState::GetInstance().setState(2);
			}
		}
	}
}