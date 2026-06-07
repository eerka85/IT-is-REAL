#include "raylib.h"
#include <stdlib.h>

void draw_rec_but_txt(Rectangle button, const char txt[], int font_siz, Color color);

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

    Texture pong_logo = LoadTexture("pixilart-drawing.png"); //800 x 450

    float rec_w = 100.0f;
    float rec_gap = 20.0f; //20 is the gap between the PONG and button
    Rectangle button_start = { 
        (screenWidth / 2) - (rec_w / 2), //half of width 
        ((screenHeight / 2) - (pong_logo.height / 2)) + pong_logo.height + rec_gap, 
        100, // width
        70   // height                             
    };
    Color color_start;

    int ball_radius = 10;
    float Y_ball_speed = 50.0f;
    float X_ball_speed = 50.0f;

    
    while(!WindowShouldClose()){ //start menu
        if(CheckCollisionPointRec(GetMousePosition(), button_start)){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                break;
            }
            color_start = GRAY;
        }
        else{
            color_start = BLUE;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(pong_logo, (screenWidth / 2) - (pong_logo.width / 2), (screenHeight / 2) - (pong_logo.height / 2), WHITE);
            draw_rec_but_txt(button_start, "PLAY", 20, color_start);
        EndDrawing();

    }


    CloseWindow();
}

void draw_rec_but_txt(Rectangle button, const char txt[], int font_siz, Color color){
    DrawRectangle(button.x, button.y, button.width, button.height, color);
    DrawText(txt, (button.x + (button.width / 2)) - (MeasureText(txt, font_siz) /2), (button.y + (button.height / 2)) - (font_siz / 2), font_siz, RED);
}