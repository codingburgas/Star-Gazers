#include "menu.h"
#include "quiz.h"

void menu() {
	const int screenWidth = 1920;
	const int screenHeight = 975;

	InitWindow(screenWidth, screenHeight, "Star Gazers Quiz");

	Vector2 mousePosition = GetMousePosition();

	const Rectangle startQuizButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	const Rectangle rulesButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 90, 270, 100 };
	const Rectangle exitButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 80, 270, 100 };

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		// Buttons logic.
		bool isMouseOverStart = CheckCollisionPointRec(mousePosition, startQuizButton);
		DrawRectangleRec(startQuizButton, (isMouseOverStart ? SKYBLUE : BLUE));
		DrawText("Start", screenWidth / 2 - 50, screenHeight / 2 - 235, 50, BLACK);

		if (isMouseOverStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			quiz();
		}

		bool isMouseOverRules = CheckCollisionPointRec(mousePosition, rulesButton);
		DrawRectangleRec(rulesButton, (isMouseOverRules ? GREEN : LIME));
		DrawText("Rules", screenWidth / 2 - 50, screenHeight / 2 - 65, 50, BLACK);

		if (isMouseOverRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			;
		}

		bool isMouseOverExit = CheckCollisionPointRec(mousePosition, exitButton);
		DrawRectangleRec(exitButton, (isMouseOverExit ? PINK : RED));
		DrawText("Exit", screenWidth / 2 - 25, screenHeight / 2 + 105, 50, BLACK);
		if (isMouseOverExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			CloseWindow();
		}

		EndDrawing();
	}
}