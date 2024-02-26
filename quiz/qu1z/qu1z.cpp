#include "quiz.h"

// Define constants for maximum number of questions and options
#define MAXQUESTIONS 10
#define MAXOPTIONS 4

using namespace std;

// Define a structure for each question, containing the question text, options, and correct option index
struct Question {
    string question;
    vector<string> options; // Array of options
    int correctOption;
};

// Function to check if mouse click occurred on an option
bool CheckMouseClickOnOption(int optionIndex, int mouseY) {
    // Check if the mouse is within the bounding box of the option and left mouse button is pressed
    return (GetMouseX() >= 100 && GetMouseX() <= 300 && GetMouseY() >= 150 + 30 * optionIndex && GetMouseY() <= 150 + 30 * optionIndex + 20 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void quiz() {
    // Array of questions with their options and correct answers
    Question questions[MAXQUESTIONS] = {
    {"What is the closest star to Earth?",
     {"a) Alpha Centauri", "b) Proxima Centauri", "c) Betelgeuse", "d) The Sun (Correct Answer)"},
     3},
    {"How many planets are there in our solar system?",
     {"a) Six", "b) Nine", "c) Eight (Correct Answer)", "d) Ten"},
     2},
    {"What is the name of the largest planet in our solar system?",
     {"a) Mars", "b) Jupiter (Correct Answer)", "c) Saturn", "d) Neptune"},
     1},
    {"What is the Great Red Spot on Jupiter?",
     {"a) Volcano", "b) Giant Storm (Correct Answer)", "c) Desert", "d) Polar Ice Cap"},
     1},
    {"Which planet is known as the \"Red Planet\"?",
     {"a) Venus", "b) Jupiter", "c) Mars (Correct Answer)", "d) Mercury"},
     2},
    {"What is a satellite, and how does it differ from a planet?",
     {"a) A planet is a man-made object in orbit; a satellite is a natural celestial body.",
      "b) A planet orbits a star; a satellite orbits a planet (Correct Answer)",
      "c) A planet is a small celestial body; a satellite is a large celestial body.",
      "d) A satellite orbits a star; a planet orbits another planet."},
     1},
    {"Can you name any two moons of Saturn?",
     {"a) Europa and Ganymede",
      "b) Titan and Enceladus (Correct Answer)",
      "c) Io and Callisto",
      "d) Triton and Charon"},
     1},
    {"What is a comet, and what is its composition?",
     {"a) A rocky planet; composed of metals.",
      "b) A celestial body with a tail; composed of ice, dust, and volatile gases (Correct Answer)",
      "c) A type of asteroid; composed of solid rock.",
      "d) A gas giant; composed mainly of hydrogen and helium."},
     1},
    {"How does the force of gravity influence objects in space?",
     {"a) It repels objects away from each other.",
      "b) It has no effect in space.",
      "c) It attracts objects with mass towards each other (Correct Answer)",
      "d) It creates magnetic fields."},
     2},
    {"What is the name of the galaxy that includes our solar system?",
     {"a) Andromeda",
      "b) Triangulum",
      "c) The Milky Way (Correct Answer)",
      "d) Sombrero"},
     2}
    };

    // Define screen dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    int currentQuestion = 0;
    int selectedOption = -1;
    bool answered = false;
    int score = 0;

    // Clear the console screen
    system("CLS");

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (!answered) {
            // Check if the mouse clicked on any option
            for (int i = 0; i < MAXOPTIONS; i++) {
                if (CheckMouseClickOnOption(i, GetMouseY())) {
                    selectedOption = i; // Update the selected option
                    break;
                }
            }
            // Check if an option is selected
            if (selectedOption >= 0) {
                // If the selected option is correct, increment the score
                if (selectedOption == questions[currentQuestion].correctOption) {
                    score++;
                }
                answered = true; // Mark the question as answered
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE); // Clear the screen

        // Display the current question
        DrawText(questions[currentQuestion].question.c_str(), 100, 100, 20, BLACK);
        // Display the options for the current question
        for (int i = 0; i < MAXOPTIONS; i++) {
            DrawText(questions[currentQuestion].options[i].c_str(), 100, 150 + 30 * i, 20, BLACK);
        }

        // Display feedback for answered question
        if (answered) {
            // If the selected option is correct, display "Correct!", otherwise display "Incorrect!"
            if (selectedOption == questions[currentQuestion].correctOption) {
                DrawText("Correct!", 100, 400, 20, GREEN);
            }
            else {
                DrawText("Incorrect!", 100, 400, 20, RED);
            }
        }

        EndDrawing(); // End drawing frame

        // Reset if answer was given
        if (answered && IsKeyPressed(KEY_ENTER)) {
            currentQuestion++; // Move to the next question
            selectedOption = -1; // Reset selected option
            answered = false; // Reset answered flag
            // If all questions have been answered, exit the loop
            if (currentQuestion >= MAXQUESTIONS) 
                break; // Quiz finished
        }
    }
        // Display score

    CloseWindow(); // Close the window

    system("CLS"); // Clear console screen
    cout << "Your score is: " << score << "/" << MAXQUESTIONS << endl;
}