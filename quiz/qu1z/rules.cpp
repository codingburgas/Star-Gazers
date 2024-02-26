#include "raylib.h" // Include Raylib library
#include "menu.h" // Include header file for menu functions
#include "quiz.h" // Include header file for quiz functions
#include <iostream>

void displayRules() {
    // Clear the screen
    ClearBackground(RAYWHITE);

    // Display rules text on the window
    DrawText("Rules:", 100, 100, 20, BLACK);
    DrawText("1. Answer the questions to the best of your ability.", 100, 150, 20, BLACK);
    DrawText("2. Each correct answer earns you points.", 100, 180, 20, BLACK);
    DrawText("3. There may be multiple-choice questions.", 100, 210, 20, BLACK);
    DrawText("4. Enjoy and learn about stars!", 100, 240, 20, BLACK);
    DrawText("Press any key to return to menu.", 100, 270, 20, BLACK);

    // Wait for any key press to return to the menu
    while (!IsKeyPressed(KEY_ANY))
    {
        // Required to keep the window open and responsive
        BeginDrawing();
        EndDrawing();
    }
}

void menu() {
    const int screenWidth = 1000; // Define screen width
    const int screenHeight = 700;

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
            displayRules();
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

int main() {
    menu(); // Call the menu function
}