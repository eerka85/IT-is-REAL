#include "raylib.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Test - Setup Successful");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    //zalozeni veci
    float my_button_size_a = 100;
    int button_txt_font_size = 20;
    Rectangle button = {(screenWidth / 2) - (my_button_size_a /2), (screenHeight / 2) - (my_button_size_a /2), my_button_size_a, my_button_size_a};
    
    

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            if(CheckCollisionPointRec(GetMousePosition(), button)){
                if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
                    ClearBackground(RAYWHITE);
                    DrawRectangle(button.x, button.y, button.width, button.height, BLUE);
                    DrawText("BUTTON", button.x + (my_button_size_a /2) - (MeasureText("BUTTON", button_txt_font_size) / 2), button.y  + (my_button_size_a /2) - (button_txt_font_size / 2), button_txt_font_size, YELLOW);
                }
                else{
                    DrawRectangle(button.x, button.y, button.width, button.height, RED);
                    DrawText("BUTTON", button.x + (my_button_size_a /2) - (MeasureText("BUTTON", button_txt_font_size) / 2), button.y  + (my_button_size_a /2) - (button_txt_font_size / 2), button_txt_font_size, YELLOW);
                }
            }
            else{
                DrawRectangle(button.x, button.y, button.width, button.height, GRAY);
                DrawText("BUTTON", button.x + (my_button_size_a /2) - (MeasureText("BUTTON", button_txt_font_size) / 2), button.y  + (my_button_size_a /2) - (button_txt_font_size / 2), button_txt_font_size, YELLOW);
            }
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}