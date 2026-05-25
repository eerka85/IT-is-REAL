#include <stdio.h>
#include <stdlib.h>
void clean_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
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
int change_pos_B(int velikost_X, char pole[][velikost_X], int vel_BY, int vel_BX, int poz_BY, int poz_BX){
    pole[poz_BY + vel_BY][poz_BX + vel_BX] = 'O';
    pole[poz_BY][poz_BX] = '#';
    poz_BX = 
}
int main(){
    int velikost_Y = input_int(1, 2700000, "velikost pole: ");
    int velikost_X = (15 * velikost_Y) /10;
    char pole[velikost_Y][velikost_X];

    int poz_BY = velikost_Y/2;
    int poz_BX = velikost_X/2;

    int vel_BY = -1;
    int vel_BX = 1;

    //vynulovani pole na #
    for(int i = 0; i< velikost_Y; i++){
        for(int j = 0; j< velikost_X; j++){
            pole[i][j] = '#';
        }
    }


    return 0;
}