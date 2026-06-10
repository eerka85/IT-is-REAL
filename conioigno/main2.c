#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>


int main(){
    int input = 0;
    bool is_prefix = false;
    while (input != 27){
        is_prefix = false;
        int input = _getch();
        if(input == 0 || input == 224){
            input = _getch();
            is_prefix = true;
        }



    }
    return 0;
}