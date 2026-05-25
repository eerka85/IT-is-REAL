#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define RED     "\033[31m"
#define RESET   "\033[0m"
#define BOLD    "\033[1m"

void clean_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}
void del_screen(){
	system("cls");
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
    pole[*poz_BY][*poz_BX] = '#';
    *poz_BY = *poz_BY + vel_BY;
    *poz_BX = *poz_BX + vel_BX;
}
void print_pole(char hastag_string[], int velikost_Y, int velikost_X, char pole[velikost_Y][velikost_X], int poz_BY){
    for(int i = 0; i< velikost_Y; i++){
        if(i == poz_BY){
            for(int j = 0; j< velikost_X; j++){
                if(pole[i][j] == 'O'){
                    printf(RED BOLD "%c" RESET, pole[i][j]);
                }
                else{
                    printf("%c", pole[i][j]);
                }
            }
        }
        else{
            printf("%s", hastag_string);
        }
        printf("\n");
    }
}
int main(){
    int velikost_Y = input_int(1, 2700000, "velikost pole: ");
    int velikost_X = velikost_Y * 2;
    char pole[velikost_Y][velikost_X];

    int poz_BY = velikost_Y / 2;
    int poz_BX = velikost_X / 2;

    int vel_BY = -1;
    int vel_BX = 1;

    char hastag_string[velikost_X+1];
    for(int i = 0; i < velikost_X; i++){
        hastag_string[i] = '#';
    }
    hastag_string[velikost_X] = '\0';

    //vynulovani pole na #
    for(int i = 0; i< velikost_Y; i++){
        for(int j = 0; j< velikost_X; j++){
            pole[i][j] = '#';
        }
    }

    while(1){
        print_pole(hastag_string, velikost_Y, velikost_X, pole, poz_BY);
        if(poz_BY == 0 || poz_BY == velikost_Y - 1){
            vel_BY = vel_BY * (-1);
        }
        if(poz_BX == 0 || poz_BX == velikost_X - 1){
            vel_BX = vel_BX * (-1);
        }
        change_pos_B(velikost_Y, velikost_X, pole, vel_BY, vel_BX, &poz_BY, &poz_BX);
        Sleep(20);
        del_screen();
    }//main while ig

    return 0;
}