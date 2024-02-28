#include "menu.h" // Include header file for menu functions
#include "quiz.h" // Include header file for quiz functions
#include "rules.h" 

void menu() {
	const int screenWidth = 1000; // Define screen width
	const int screenHeight = 700; // Define screen height
	
	// Initialize window with a title
	InitWindow(screenWidth, screenHeight, "Star Gazers Quiz");
	// Initialize vector to store mouse position
	Vector2 mousePosition = GetMousePosition();

	const Rectangle startQuizButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 260, 270, 100 };
	const Rectangle rulesButton = { (screenWidth / 2) - 110, (screenHeight / 2) - 90, 270, 100 };
	const Rectangle exitButton = { (screenWidth / 2) - 110, (screenHeight / 2) + 80, 270, 100 };
	
	// Main loop for the menu
	while (!WindowShouldClose()) {
		
		// Update mouse position
		mousePosition = GetMousePosition();
		// Begin drawing
		BeginDrawing();
		// Clear background
		

		// Draw start quiz button
		bool isMouseOverStart = CheckCollisionPointRec(mousePosition, startQuizButton);
		DrawRectangleRec(startQuizButton, (isMouseOverStart ? SKYBLUE : BLUE));
		DrawText("Start", screenWidth / 2 - 50, screenHeight / 2 - 235, 50, BLACK);

		// Check if start quiz button is clicked
		if (isMouseOverStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			// Call quiz function to start the quiz
			quiz();
		}

		// Draw rules button
		bool isMouseOverRules = CheckCollisionPointRec(mousePosition, rulesButton);
		DrawRectangleRec(rulesButton, (isMouseOverRules ? GREEN : LIME));
		DrawText("Rules", screenWidth / 2 - 50, screenHeight / 2 - 65, 50, BLACK);

		if (isMouseOverRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			rules();
		}

		// Draw exit button
		bool isMouseOverExit = CheckCollisionPointRec(mousePosition, exitButton);
		DrawRectangleRec(exitButton, (isMouseOverExit ? PINK : RED));
		DrawText("Exit", screenWidth / 2 - 25, screenHeight / 2 + 105, 50, BLACK);

		// Check if exit button is clicked
		if (isMouseOverExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			// Close the window
			CloseWindow();
		}
		ClearBackground(WHITE);

		// End drawing
		EndDrawing();
	}
}