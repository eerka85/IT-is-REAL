#include "raylib.h"

int draw_sq_button(char but_txt[], int but_font_size, Rectangle button, float my_button_size_a, Color B_color, Color T_color);


int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Test - Setup Successful");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    //zalozeni veci
    float A_but_size = 100;
    Rectangle A_button = {(screenWidth / 2) - (A_but_size /2), (screenHeight / 2) - (A_but_size /2), A_but_size, A_but_size};
    int A_but_font_size = 20;
    char A_but_txt[] = {"BUTTON 1"};

    float B_but_size = 100;
    Rectangle B_button = {(screenWidth / 4) - (B_but_size /2), (screenHeight / 2) - (B_but_size /2), B_but_size, B_but_size};
    int B_but_font_size = 10;
    char B_but_txt[] = {"BUTTON 2"};

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC keyr
        // Update
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
            draw_sq_button(A_but_txt, A_but_font_size, A_button, A_but_size, RED, ORANGE);
            draw_sq_button(B_but_txt, B_but_font_size, B_button, B_but_size, BLUE, ORANGE);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

int draw_sq_button(char but_txt[], int but_font_size, Rectangle button, float my_button_size_a, Color B_color, Color T_color){
    ClearBackground(RAYWHITE);
    DrawRectangle(button.x, button.y, button.width, button.height, B_color);
    DrawText(but_txt, (button.x) + (my_button_size_a / 2) - (MeasureText(but_txt, but_font_size) /2), (button.y) + (my_button_size_a / 2) - (but_font_size / 2), but_font_size, T_color);
    return 0;
}