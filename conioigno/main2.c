#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"


int main(){
    int input = 0;
    bool is_prefix = false;
    int U_poz = 0;
    
    int velikost = 4;
    char menu[velikost][100];
    strcpy(menu[0], "moznost 1");
    strcpy(menu[1], "moznost 2");
    strcpy(menu[2], "moznost 3");
    strcpy(menu[3], "moznost 4");
    

    

    do{
        is_prefix = false;
        int input = _getch();
        if(input == 0 || input == 224){
            input = _getch();
            is_prefix = true;
        }

        if(is_prefix && input == 80){
            if(U_poz == 3){

            }
            else{
                U_poz++;
            }
        }
        if(is_prefix && input == 72){
            if(U_poz == 0){

            }
            else{
                U_poz--;
            }
        }

        for(int i = 0; i<velikost; i++){
            if(i == U_poz){
                printf(ANSI_COLOR_RED "%s\n", menu[i], ANSI_COLOR_RESET);
            }
            else{
                printf(ANSI_COLOR_BLUE "%s\n", menu[i], ANSI_COLOR_RESET);
            }
        }




    }while (input != 97);
    return 0;
}