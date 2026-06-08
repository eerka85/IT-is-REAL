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

    const float Speedup_modifier = 1.5f;


    Texture pong_logo = LoadTexture("pixilart-drawing.png"); //all 800 x 450 
    if(!IsTextureValid(pong_logo)){
        TraceLog(LOG_ERROR, "Failed to load texture: pixilart-drawing.png");
        UnloadTexture(pong_logo);
        CloseWindow();
    }
    
    Texture player1_won = LoadTexture("player1won.png");
    if(!IsTextureValid(player1_won)){
        TraceLog(LOG_ERROR, "Failed to load texture: player1won.png");
        UnloadTexture(pong_logo);
        UnloadTexture(player1_won);
        CloseWindow();
    }

    Texture player2_won = LoadTexture("player2won.png");
    if(!IsTextureValid(player2_won)){
        TraceLog(LOG_ERROR, "Failed to load texture: player2won.png");
        UnloadTexture(pong_logo);
        UnloadTexture(player1_won);
        UnloadTexture(player2_won);
        CloseWindow();
    }
    
    float scale = screenWidth / pong_logo.width;

    Vector2 texture_pos = {
        (float)(screenWidth / 2) - ((pong_logo.width * scale) / 2),
        (float)(screenHeight / 2) - ((pong_logo.height * scale) / 2)
    };

    float rec_w = 100.0f;
    Rectangle button_start = { 
        (screenWidth / 2) - (rec_w / 2), //half of width 
        ((screenHeight / 2) + ((pong_logo.height * scale) / 2)) - 200, 
        100, // width
        70   // height                             
    };
    Color color_start;

    Color speed_text;


    float ball_radius = 10.0f;
    float Y_ball_speed = 500.0f;
    float X_ball_speed = -500.0f;

    Vector2 ball_pos = {
        screenWidth / (float) 2,
        screenHeight / (float) 2
    };


    const float P_width = 20.0f;
    const float P_height = 200.0f;

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

    const  char *speed_txt = 0;

    
    
    while(!WindowShouldClose()){ //start menu
        if(IsKeyPressed(KEY_ENTER)){
            break;
        }
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
            DrawTextureEx(pong_logo, texture_pos, 0, scale, WHITE);
            draw_rec_but_txt(button_start, "PLAY", 20, color_start);
        EndDrawing();

    }

    HideCursor();

    while(!WindowShouldClose()){ //start menu
        
        if(ball_pos.y < ball_radius || ball_pos.y > (screenHeight - ball_radius)){
            Y_ball_speed *= -1;
        }
        if(ball_pos.x < ball_radius){
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawTextureEx(player2_won, texture_pos, 0, scale, WHITE);
            EndDrawing();
            WaitTime(3);
            break;
        }
        if(ball_pos.x > (screenWidth - ball_radius)){
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawTextureEx(player1_won, texture_pos, 0, scale, WHITE);
            EndDrawing();
            WaitTime(3);
            break;
        }

        

        if(CheckCollisionCircleRec(ball_pos, ball_radius, Player1)){
            if((ball_pos.x + ball_radius) <= P_width){
                ball_pos.x = P_width + 5 + ball_radius; //idikkkkdkkk
            }
            X_ball_speed *= -1;
        }
        if(CheckCollisionCircleRec(ball_pos, ball_radius, Player2)){
            if((ball_pos.x + ball_radius) >= (screenWidth - P_width)){
                ball_pos.x = (screenWidth - P_width - ball_radius) - 5;
            }
            X_ball_speed *= -1;
        }
        if(IsKeyDown(KEY_SPACE)){
            ball_pos.y += GetFrameTime() * Y_ball_speed * Speedup_modifier;
            ball_pos.x += GetFrameTime() * X_ball_speed * Speedup_modifier;
        }
        else{
            ball_pos.y += GetFrameTime() * Y_ball_speed;
            ball_pos.x += GetFrameTime() * X_ball_speed;
        }
        

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

        if(X_ball_speed > 0){
             X_ball_speed += GetFrameTime() +0.05;
        }
        else{
            X_ball_speed -= GetFrameTime() +0.05;
        }
       
        if(Y_ball_speed > 0){
             Y_ball_speed += GetFrameTime() +0.05;
        }
        else{
            Y_ball_speed -= GetFrameTime() +0.05;
        }
        if(IsKeyDown(KEY_SPACE)){
            speed_txt = TextFormat("Current X ball speed: %f\nCurrent Y ball speed: %f", X_ball_speed * Speedup_modifier, Y_ball_speed * Speedup_modifier);
            speed_text = RED;
        }
        else{
            speed_txt = TextFormat("Current X ball speed: %f\nCurrent Y ball speed: %f\n( press SPACE to speed up! )", X_ball_speed, Y_ball_speed);
            speed_text = BLACK;
        }
        


        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircle(ball_pos.x, ball_pos.y, ball_radius, RED);
            DrawRectangle(Player1.x, Player1.y, Player1.width, Player1.height, DARKBLUE);
            DrawRectangle(Player2.x, Player2.y, Player2.width, Player2.height, DARKBLUE);
            DrawText(speed_txt, 10, 10, 20, speed_text);
        EndDrawing();
    }

    UnloadTexture(pong_logo);
    UnloadTexture(player1_won);
    UnloadTexture(player2_won);
    CloseWindow();
}

void draw_rec_but_txt(Rectangle button, const char txt[], int font_siz, Color color){
    DrawRectangle(button.x, button.y, button.width, button.height, color);
    DrawText(txt, (button.x + (button.width / 2)) - (MeasureText(txt, font_siz) /2), (button.y + (button.height / 2)) - (font_siz / 2), font_siz, RED);
}
