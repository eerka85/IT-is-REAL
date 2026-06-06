#include "raylib.h"
#include <stdlib.h>

int main(){
    const int screenWidth_jkjk = 800; //idk jak velkou obrazovku ma kazdej
    const int screenHeight_jkjk = 450;
    InitWindow(screenWidth_jkjk, screenHeight_jkjk, "PONG");
    SetWindowState(FLAG_WINDOW_RESIZABLE);
    MaximizeWindow();
    int screenWidth = GetScreenWidth(); //pouzivat toto
    int screenHeight = GetScreenHeight();
    SetWindowMinSize(screenWidth, screenHeight); //jinak to da zase 800 450
    ClearWindowState(FLAG_WINDOW_RESIZABLE); //flagy jsoi lowk cool

    Texture pong_logo = LoadTexture("pixilart-drawing.png");

    int ball_radius = 10;
    float Y_ball_speed = 50.0f;
    float X_ball_speed = 50.0f;

    
    while(!WindowShouldClose()){

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(pong_logo, 10, 10, WHITE);
        EndDrawing();

    }


    CloseWindow();
}