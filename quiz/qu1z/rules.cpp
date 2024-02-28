#include "quiz.h"
#include "menu.h"

void rules() {
    // Define a rectangle representing the button to start the quiz
    Rectangle toGame = { GetScreenWidth() / 2 + 300, GetScreenHeight() / 2 + 250, 120, 50 };

    // Main loop for the rules screen
    while (!WindowShouldClose()) { // Continue running until the window is closed

        //Defines the key that makes the player leave the rules
        SetExitKey(KEY_ESCAPE);

        // Get the current mouse position
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();

        // Clear the background to white
        ClearBackground(WHITE);

        // Draw instruction text
        DrawText("press ESC to go back", GetScreenWidth() / 2 - 425, GetScreenHeight() / 2 + 275, 20, BLACK);
        DrawRectangleRec(toGame, (CheckCollisionPointRec(mousePosition, toGame) ? GREEN : LIME));
        DrawRectangleLines(GetScreenWidth() / 2 - 390, GetScreenHeight() / 2 - 270,800, 450, ORANGE);
        DrawText("Welcome to our quiz game!", 190, 165, 25, BLACK); // Black text
        DrawText("You're about to embark on a journey through space.", 190, 200, 25, BLACK);
        DrawText("Get ready to explore our solar system and learn", 190, 235, 25, BLACK);
        DrawText("fascinating facts! Click 'Start' to begin the quiz", 190, 270, 25, BLACK);
        DrawText("or 'Exit' if you'd like to leave. Press 'Enter' after", 190, 305, 25, BLACK);
        DrawText("each question to proceed. Good luck!", 190, 340, 25, BLACK);
        DrawRectangleRec(toGame, (CheckCollisionPointRec(mousePosition, toGame) ? SKYBLUE : BLUE));
        EndDrawing();

        // Check if the left mouse button is pressed and if it's within the button area
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, toGame))
        {
            quiz(); // Call the quiz function
        }
    }
}
