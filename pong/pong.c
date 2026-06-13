#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h> //kbhit
#include <sys/time.h> //master milisekunf
#include <stdbool.h>
//Cau verco jestli se sem koukas :)
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

void clean_buffer();
void del_screen();
int input_int(int min, int max, char vypis[]);
int print_soub(char volba_art[], int color);
void change_pos_B(int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X], int vel_BY, int vel_BX, int *poz_BY, int *poz_BX);
void print_pole(bool speeding_up, int A1_points, int A2_points,  int ball_print_DELAY_MICROseconds, int poz_A1, int poz_A2, int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X]);

int main(){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);//ai schovani kurzoru
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = FALSE; 
    SetConsoleCursorInfo(out, &cursorInfo);

    struct timeval start, stop;
    int ball_print_DELAY_MICROseconds = 40000;
    bool speeding_up = false;
    int cycles_count = 0;

    int koeficient_rozmeru_X = 3;
    int velikost_Y = 20; //velikost cely veci
    int velikost_X = velikost_Y * koeficient_rozmeru_X;
    char pole[velikost_Y][velikost_X];

    int poz_BY = velikost_Y / 2;
    int poz_BX = velikost_X / 2;

    int poz_A1 = velikost_Y/2;
    int poz_A2 = velikost_Y/2;

    int A1_points = 0;
    int A2_points = 0;

    int vel_BY = 1;
    if(rand()%2 == 0){
        vel_BY = -1;
    }

    int vel_BX = 1;
    if(rand()%2 == 0){
        vel_BX = -1;
    }

    int input_klaves = 0;
    //vynulovani pole na  
    for(int i = 0; i< velikost_Y; i++){
        for(int j = 0; j< velikost_X; j++){
            pole[i][j] = '#';
        }
    }

    while(1){
        gettimeofday(&start, NULL); //prvni pocatek

        print_soub("pong.txt", 0);
        printf("\nCONTROLS: 1. player 1: W & S == move left bar up and down\n             player 2: O & K == move right bar up and down\n          2. SPACE == speed up (a little)\npress ENTER to play...");
        getchar();
        system("cls");
        while(2){
            if(_kbhit()){
                input_klaves = getch();
                if(input_klaves == 119 && poz_A1 != 0){ //A1
                    poz_A1 = poz_A1 -1;
                }
                if(input_klaves == 115 && poz_A1 != velikost_Y-3){
                    poz_A1 = poz_A1 +1;
                }

                if(input_klaves == 111 && poz_A2 != 0){ //A2
                    poz_A2 = poz_A2 -1;
                }
                if(input_klaves == 107 && poz_A2 != velikost_Y-3){
                    poz_A2 = poz_A2 +1;
                }

                if(input_klaves == 32){
                    speeding_up = true;
                }
                else{
                    speeding_up = false;
                }
            }

            gettimeofday(&stop, NULL); //abych nemusel pouzit Sleep
            long long start_usec = (long long)start.tv_sec * 1000000 + start.tv_usec;
            long long stop_usec = (long long)stop.tv_sec * 1000000 + stop.tv_usec;
            long long elapsed_usec = stop_usec - start_usec;


            if( elapsed_usec > ball_print_DELAY_MICROseconds/4){ // DDD a CCC
                if(cycles_count == 4){ //ball

                    if(poz_BX == 0 || poz_BX == velikost_X - 1){ //odrazeni o strany
                        vel_BX = vel_BX * (-1); //prevraceni hodnoty
                    }
                    if(poz_BY == 0 || poz_BY == velikost_Y - 1){ //odrazeni o strany
                        vel_BY = vel_BY * (-1);
                    }
                    change_pos_B(velikost_Y, velikost_X, pole, vel_BY, vel_BX, &poz_BY, &poz_BX);


                    if( poz_BX == 0 && !( (poz_BY == poz_A1) ||  (poz_BY == poz_A1 +1) || (poz_BY == poz_A1 +2)  ) ){//losing? A1
                        system("cls");
                        print_pole(speeding_up, A1_points, A2_points, ball_print_DELAY_MICROseconds, poz_A1, poz_A2, velikost_Y, velikost_X, pole);
                        printf("\n");
                        print_soub("lost1.txt", 1);
                        printf("\n");

                        A2_points++;
                        
                        getchar();
                        break;
                    }
                    if( poz_BX == velikost_X-1 && !( (poz_BY == poz_A2) ||  (poz_BY == poz_A2 +1) || (poz_BY == poz_A2 +2)  ) ){//losing? A2
                        system("cls");
                        print_pole(speeding_up, A1_points, A2_points, ball_print_DELAY_MICROseconds, poz_A1, poz_A2, velikost_Y, velikost_X, pole);
                        printf("\n");
                        print_soub("lost2.txt", 2);
                        printf("\n");

                        A1_points++;
                        
                        getchar();
                        break;
                    }

                    
                    
                    if(ball_print_DELAY_MICROseconds > 1000){ //minimum hranice ball_print_DELAY_MICROseconds
                        ball_print_DELAY_MICROseconds -= 50;
                    }
                    //speeding_up = false;
                    cycles_count = 0;
                }

                print_pole(speeding_up, A1_points, A2_points, ball_print_DELAY_MICROseconds, poz_A1, poz_A2, velikost_Y, velikost_X, pole);
                cycles_count++;
                del_screen();
                gettimeofday(&start, NULL); //novej pocatek
            }

        }//main while ig
        system("cls");
        print_soub("again.txt", 0);
        getchar();
        //RESET
        poz_BY = velikost_Y / 2;
        poz_BX = velikost_X / 2;

        poz_A1 = velikost_Y/2;
        poz_A2 = velikost_Y/2;

        vel_BY = 1;
        if(rand()%2 == 0){
            vel_BY = -1;
        }

        vel_BX = 1;
        if(rand()%2 == 0){
            vel_BX = -1;
        }

        ball_print_DELAY_MICROseconds = 40000;

        input_klaves = 0;
        //vynulovani pole na  
        for(int i = 0; i< velikost_Y; i++){
            for(int j = 0; j< velikost_X; j++){
                pole[i][j] = '#';
            }
        }

    }
    
}
void clean_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}
void del_screen(){
	COORD cursorPosition;// ts is highkey ai
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
int input_int(int min, int max, char vypis[]){
	int tmp = 0;
	while(1) {
		printf("%s", vypis);
		int is_input_valid = scanf("%d", &tmp);
		clean_buffer();
		if(is_input_valid == 0 || tmp <min || tmp >max) {
			printf(  "##failed to load number##\n" );
			continue;
		}
		else {
			return tmp;
		}
	}
}
int print_soub(char volba_art[], int color){
    char direction_soub[] = {"C:/Users/johnn/Desktop/programy C/random ahh programy + skola/IT-is-REAL/pong/"};
    strcat(direction_soub, volba_art);
    char buffer[256];

    FILE * soubor = fopen(direction_soub, "r");
    if(soubor == NULL){
        return 1;
    }
    while(fgets(buffer, sizeof(buffer), soubor)){
        switch(color){
            case 1:
                printf(RED "%s" RESET, buffer);
            break;
            case 2:
                printf(BLUE "%s" RESET, buffer);
            break;
            default:
                printf("%s", buffer);
            break;
        }
    }
    printf("\n");

    fclose(soubor);
}
void change_pos_B(int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X], int vel_BY, int vel_BX, int *poz_BY, int *poz_BX){
    pole[*poz_BY + vel_BY][*poz_BX + vel_BX] = 'O';
    pole[*poz_BY][*poz_BX] = ' ';
    *poz_BY = *poz_BY + vel_BY;
    *poz_BX = *poz_BX + vel_BX;
}
void print_pole(bool speeding_up, int A1_points, int A2_points,  int ball_print_DELAY_MICROseconds, int poz_A1, int poz_A2, int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X]){
    int A1_pomoc = 0;
    int A2_pomoc = 0;
    // 1. Print Top Border
    for(int i = 0; i < velikost_X + 4; i++) printf("#");
    printf("\n");

    // 2. Print Grid
    for(int i = 0; i < velikost_Y; i++){
        if(i == poz_A1){
            A1_pomoc = 3;//velikost mredky 1
        }
         if(i == poz_A2){
            A2_pomoc = 3;//velikost mredky 2
        }

        if(A1_pomoc >0){
            printf("#"); // Left wall
            printf(BOLD RED "D" RESET); //odrazeci vec
            A1_pomoc--;
        }
        else{
            printf("# "); // Left wall
        }

        for(int j = 0; j < velikost_X; j++){
            if(pole[i][j] == 'O') printf(GREEN BOLD "O" RESET);
            else printf(" ");
        }
        if(A2_pomoc >0){
            printf(BOLD BLUE "C" RESET); //odrazeci vec
            printf("#\n"); 
            A2_pomoc--;
        }
        else{
            printf(" #\n"); // Right wall
        }
    }

    // 3. Print Bottom Border
    for(int i = 0; i < velikost_X + 4; i++) printf("#");
    printf("\n");
    printf("ball_print_DELAY_MICROseconds: %d\n", ball_print_DELAY_MICROseconds);
    printf("Speedup?: %s\n", speeding_up ? "true " : "false"); 
    printf("SCORE: P1 = %d\n       P2 = %d", A1_points, A2_points);

}

