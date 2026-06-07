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



    SetTargetFPS(60);



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


    float ball_radius = 10.0f;
    float Y_ball_speed = 500.0f;
    float X_ball_speed = 500.0f;
    float ball_pos_x = (screenWidth /2);
    float ball_pos_y = (screenHeight /2);


    const float P_width = 20.0f;
    const float P_height = 120.0f;

    const float P_speed = 10.0f;

    const float p1_pos_x = 0.0f;
    float p1_pos_y = (screenHeight /2) - (P_height /2);
    Rectangle Player1 = { 
        p1_pos_x, 
        p1_pos_y, 
        P_width, // width
        P_height   // height                             
    };

    const float p2_pos_x = screenWidth - P_width;
    float p2_pos_y = (screenHeight /2) - (P_height /2);
    Rectangle Player2 = { 
        p2_pos_x, 
        p2_pos_y, 
        P_width, // width
        P_height   // height                             
    };

    
    
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

    HideCursor();

    while(!WindowShouldClose()){ //start menu
        
        if(ball_pos_y < ball_radius || ball_pos_y > (screenHeight - ball_radius)){
            Y_ball_speed *= -1;
        }
        if(ball_pos_x < ball_radius + P_width || ball_pos_x > ((screenWidth - P_width) - ball_radius)){
            X_ball_speed *= -1;
        }
        ball_pos_y += GetFrameTime() * Y_ball_speed;
        ball_pos_x += GetFrameTime() * X_ball_speed;

        if(IsKeyDown(KEY_UP)){
            if(Player2.y < 0){

            }
            else{
                Player2.y -= P_speed;
            }
        }
        if(IsKeyDown(KEY_DOWN)){
            if(Player2.y > (screenHeight - P_height)){

            }
            else{
                Player2.y += P_speed;
            }
        }

        if(IsKeyDown(KEY_W)){
            if(Player1.y < 0){

            }
            else{
                Player1.y -= P_speed;
            }
        }
        if(IsKeyDown(KEY_S)){
            if(Player1.y > (screenHeight - P_height)){
            }
            else{
                Player1.y += P_speed;
            }
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(ball_pos_x, ball_pos_y, ball_radius, RED);
            DrawRectangle(Player1.x, Player1.y, Player1.width, Player1.height, DARKBLUE);
            DrawRectangle(Player2.x, Player2.y, Player2.width, Player2.height, DARKBLUE);
        EndDrawing();
    }

    CloseWindow();
}

void draw_rec_but_txt(Rectangle button, const char txt[], int font_siz, Color color){
    DrawRectangle(button.x, button.y, button.width, button.height, color);
    DrawText(txt, (button.x + (button.width / 2)) - (MeasureText(txt, font_siz) /2), (button.y + (button.height / 2)) - (font_siz / 2), font_siz, RED);
}
