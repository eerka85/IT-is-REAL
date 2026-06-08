#include "raylib.h"

void draw_sq_button(char but_txt[], int but_font_size, Rectangle button, float my_button_size_a, Color B_color, Color T_color);


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
    float A_speed = -100.0f;

    float B_but_size = 100;
    Rectangle B_button = {(screenWidth / 4) - (B_but_size /2), (screenHeight / 2) - (B_but_size /2), B_but_size, B_but_size};
    int B_but_font_size = 10;
    char B_but_txt[] = {"BUTTON 2"};
    float B_speed = -50.0f;

    Color A_actual_color;
    Color B_actual_color;

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        // TODO: Update your variables here
        if(CheckCollisionPointRec(GetMousePosition(), A_button)){ //BUTTON A
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                break;
            }
            A_actual_color = GRAY;
        }
        else{
            A_actual_color = RED;
        }
        
        if(A_button.y < 0 || A_button.y > screenHeight - A_but_size){
            A_speed *= -1;
        }
        A_button.y += GetFrameTime() * A_speed;



        if(CheckCollisionPointRec(GetMousePosition(), B_button)){ //BUTTON B
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                break;
            }
            B_actual_color = GRAY;
        }
        else{
            B_actual_color = BLUE;
        }

        if(B_button.y < 0 || B_button.y > screenHeight - B_but_size){
            B_speed *= -1;
        }
        B_button.y += GetFrameTime() * B_speed;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_sq_button(A_but_txt, A_but_font_size, A_button, A_but_size, A_actual_color, ORANGE);
            draw_sq_button(B_but_txt, B_but_font_size, B_button, B_but_size, B_actual_color, ORANGE);
        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}

void draw_sq_button(char but_txt[], int but_font_size, Rectangle button, float my_button_size_a, Color B_color, Color T_color){
    DrawRectangle(button.x, button.y, button.width, button.height, B_color);
    DrawText(but_txt, (button.x) + (my_button_size_a / 2) - (MeasureText(but_txt, but_font_size) /2), (button.y) + (my_button_size_a / 2) - (but_font_size / 2), but_font_size, T_color);
}