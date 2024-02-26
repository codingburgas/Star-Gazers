#include "quiz.h"
#include "menu.h"

void rules() {
    // Define a rectangle representing the button to start the quiz
    Rectangle toGame = { GetScreenWidth() / 2 + 400, GetScreenHeight() / 2 + 400, 300, 200 };
    // Main loop for the rules screen
    while (!WindowShouldClose()) { // Continue running until the window is closed
        // Get the current mouse position
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();

        // Clear the background to white
        ClearBackground(WHITE);
        // Draw instruction text
        DrawText("press ESC to go back", 75, 915, 20, RED);
        DrawRectangleRec(toGame, (CheckCollisionPointRec(mousePosition, toGame) ? GREEN : LIME));
        DrawRectangleLines(180, 160, 1500, 750, ORANGE);
        DrawText("Welcome to our quiz game!", 190, 165, 25, BLACK); // Black text
        DrawText("You're about to embark on a journey through space.", 190, 200, 25, BLACK);
        DrawText("Get ready to explore our solar system and learn", 190, 235, 25, BLACK);
        DrawText("fascinating facts! Click 'Start' to begin the quiz", 190, 270, 25, BLACK);
        DrawText("or 'Exit' if you'd like to leave. Press 'Enter' after", 190, 305, 25, BLACK);
        DrawText("each question to proceed. Good luck!", 190, 340, 25, BLACK);
        EndDrawing();
        // Check if the left mouse button is pressed and if it's within the button area
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, toGame))
            quiz(); // Call the quiz function
    }
}
