# Quiz Master (Modernized)

## Description
A classic quiz game modernized with a new graphical interface using the Raylib library. Test your knowledge with a series of multiple-choice questions. This project is an enhancement of an original C-based quiz game, aiming for a cleaner UI and better user experience.

## Features
- Modern and intuitive user interface.
- Multiple-choice questions loaded from an external file (`KBC.txt`).
- Scoring system: 10 points for each correct answer.
- Ability to view previous scores.
- Help screen with game instructions.
- Cross-platform compatibility (thanks to Raylib).

## Screenshots
*(Placeholder for new UI screenshots once implemented)*
- *Main Menu*
- *Question Screen*
- *Score Screen*

## Getting Started

### Prerequisites
- A C compiler (like GCC or Clang).
- Raylib library installed. You can find installation instructions on the [Raylib website](https://www.raylib.com).

### Compilation
1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. **Compile the game:**
   The exact compilation command will depend on your system and how you've installed Raylib. Here's a general example for GCC on Linux, assuming Raylib is installed in a standard location:
   ```bash
   gcc GNEW.C -o QuizMaster -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```
   - For Windows (MinGW-w64), it might look like:
     ```bash
     gcc GNEW.C -o QuizMaster.exe -I<path-to-raylib-include> -L<path-to-raylib-lib> -lraylib -lopengl32 -lgdi32 -lwinmm
     ```
   - **Important:** Replace `<path-to-raylib-include>` and `<path-to-raylib-lib>` with the actual paths to your Raylib installation if it's not found automatically. Refer to the Raylib documentation for platform-specific compilation instructions.

### Running the Game
Execute the compiled program:
```bash
./QuizMaster
```
Or on Windows:
```bash
QuizMaster.exe
```

## How to Play
- Use the mouse to navigate menus and select answers.
- The game consists of a series of questions, each with four possible answers.
- Click on your chosen answer.
- Your score will be updated based on correct answers.
- You can view your previous scores from the main menu.

## Code Structure Overview (Post-Redesign)
The game is structured around a main game loop using Raylib. Key components include:
- **Initialization:** Sets up the Raylib window, loads fonts, and initializes game state.
- **Screen Management:** Uses a state variable (`currentScreen`) to control which part of the game is active (e.g., Main Menu, Question Screen, Score Screen).
- **Main Loop:**
    - Processes user input (mouse clicks).
    - Updates game logic based on the current screen and input.
    - Draws the current screen's UI elements using Raylib functions.
- **UI Rendering:** Functions dedicated to drawing each screen (e.g., `DrawMainMenuScreen()`, `DrawQuestionScreen()`). These use Raylib's drawing primitives for shapes, text, etc.
- **Input Handling:** Raylib functions like `GetMousePosition()`, `IsMouseButtonPressed()`, and `CheckCollisionPointRec()` are used for interactivity.
- **Question Loading:** Questions are read from `KBC.txt`.
- **Score Management:** Scores are saved to and read from `score.txt`.

## Contributing
Contributions are welcome! If you have ideas for improvements or find any bugs, please feel free to:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourAmazingFeature`).
3. Make your changes.
4. Commit your changes (`git commit -m 'Add some YourAmazingFeature'`).
5. Push to the branch (`git push origin feature/YourAmazingFeature`).
6. Open a Pull Request.

## Original Project
This project is a modernization of an older quiz game. The original version used `graphics.h` (Turbo C graphics). You can see the previous README content below for historical context:

---
# Quiz-Game
Concisely, this Mini Quiz Game Project using C graphics and file handling can be useful to students or professionals to test their knowledge by playing the quiz. This project can also be modified to fit your personal requirements. This quiz game is just like KBC which is created by C language and we use file handling to insert several questions .
# OUTPUT
![FRONT](https://github.com/Abhishek-kumarsingh/Quiz-Game/assets/91685785/48efba68-0d09-425a-9951-9564d99cc160)
![QUESTION](https://github.com/Abhishek-kumarsingh/Quiz-Game/assets/91685785/04efb918-52cd-4076-b2e4-0280cad79b77)

---
