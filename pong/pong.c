#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h> //kbhit
#include <sys/time.h> //master milisekunf

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

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
int input_int(int min, int max, char vypis[]) {
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
int change_pos_B(int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X], int vel_BY, int vel_BX, int *poz_BY, int *poz_BX){
    pole[*poz_BY + vel_BY][*poz_BX + vel_BX] = 'O';
    pole[*poz_BY][*poz_BX] = ' ';
    *poz_BY = *poz_BY + vel_BY;
    *poz_BX = *poz_BX + vel_BX;
}
void print_pole(int poz_A1, int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X]){
    int A1_pomoc = 0;
    // 1. Print Top Border
    for(int i = 0; i < velikost_X + 4; i++) printf("#");
    printf("\n");

    // 2. Print Grid
    for(int i = 0; i < velikost_Y; i++){
        if(i == poz_A1){
            A1_pomoc = 3;//velikost mredky
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
            if(pole[i][j] == 'O') printf(RED BOLD "O" RESET);
            else printf(" ");
        }
        printf(" #\n"); // Right wall
    }

    // 3. Print Bottom Border
    for(int i = 0; i < velikost_X + 4; i++) printf("#");
    printf("\n");
}
int main(){

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);//ai schovani kurzoru
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = FALSE; 
    SetConsoleCursorInfo(out, &cursorInfo);

    struct timeval start, stop;
    int ball_print_speed_miliseconds = 40;

    int koeficient_rozmeru_X = 3;
    int velikost_Y = 20; //velikost cely veci
    int velikost_X = velikost_Y * koeficient_rozmeru_X;
    char pole[velikost_Y][velikost_X];

    int poz_BY = velikost_Y / 2;
    int poz_BX = velikost_X / 2;

    int poz_A1 = velikost_Y/2;

    int vel_BY = -1;
    int vel_BX = 1;

    int input_sipky = 0;
    //vynulovani pole na  
    for(int i = 0; i< velikost_Y; i++){
        for(int j = 0; j< velikost_X; j++){
            pole[i][j] = '#';
        }
    }


    gettimeofday(&start, NULL); //prvni pocatek

    while(1){
        if(_kbhit()){
            input_sipky = getch();
            if(input_sipky == 119 && poz_A1 != 0){
                poz_A1 = poz_A1 -1;
            }
            if(input_sipky == 115 && poz_A1 != velikost_Y-3){
                poz_A1 = poz_A1 +1;
            }
        }

        gettimeofday(&stop, NULL); //abych nemusel pouzit Sleep
        long long start_usec = (long long)start.tv_sec * 1000000 + start.tv_usec;
        long long stop_usec = (long long)stop.tv_sec * 1000000 + stop.tv_usec;
        long long elapsed_usec = stop_usec - start_usec;

        if( elapsed_usec > ball_print_speed_miliseconds *1000){
            print_pole(poz_A1, velikost_Y, velikost_X, pole);

            if(poz_BX == 0 || poz_BX == velikost_X - 1){ //odrazeni o strany
                vel_BX = vel_BX * (-1); //prevraceni hodnoty
            }
            if(poz_BY == 0 || poz_BY == velikost_Y - 1){ //odrazeni o strany
                vel_BY = vel_BY * (-1);
            }
            change_pos_B(velikost_Y, velikost_X, pole, vel_BY, vel_BX, &poz_BY, &poz_BX);

            if( poz_BX == 0 && !( (poz_BY == poz_A1) ||  (poz_BY == poz_A1 +1) || (poz_BY == poz_A1 +2)  ) ){//losing?
                system("cls");
                printf(" YOU LOST ");
                Sleep(10000);
                exit(0);
            }
            del_screen();
            gettimeofday(&start, NULL); //novej pocatek
        }


    }//main while ig

    return 0;
}
