#include "quiz.h"

#define MAXQUESTIONS 10
#define MAXOPTIONS 4

using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption;
};


bool CheckMouseClickOnOption(int optionIndex, int mouseY) {
    return (GetMouseX() >= 100 && GetMouseX() <= 300 && GetMouseY() >= 150 + 30 * optionIndex && GetMouseY() <= 150 + 30 * optionIndex + 20 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON));
}

void quiz() {

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

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Star Gazers Quiz");

    int currentQuestion = 0;
    int selectedOption = -1;
    bool answered = false;
    int score = 0;

    system("CLS");

    while (!WindowShouldClose()) {
        // Update
        if (!answered) {
            for (int i = 0; i < MAXOPTIONS; i++) {
                if (CheckMouseClickOnOption(i, GetMouseY())) {
                    selectedOption = i;
                    break;
                }
            }

            if (selectedOption >= 0) {
                if (selectedOption == questions[currentQuestion].correctOption) {
                    score++;
                }
                answered = true;
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText(questions[currentQuestion].question.c_str(), 100, 100, 20, BLACK);
        for (int i = 0; i < MAXOPTIONS; i++) {
            DrawText(questions[currentQuestion].options[i].c_str(), 100, 150 + 30 * i, 20, BLACK);
        }

        if (answered) {
            if (selectedOption == questions[currentQuestion].correctOption) {
                DrawText("Correct!", 100, 400, 20, GREEN);
            }
            else {
                DrawText("Incorrect!", 100, 400, 20, RED);
            }
        }

        EndDrawing();

        // Reset if answer was given
        if (answered && IsKeyPressed(KEY_ENTER)) {
            currentQuestion++;
            selectedOption = -1;
            answered = false;
            if (currentQuestion >= MAXQUESTIONS) 
                break; // Quiz finished
        }
    }
        // Display score

    CloseWindow();

    system("CLS");
    cout << "Your score is: " << score << "/" << MAXQUESTIONS << endl;
}