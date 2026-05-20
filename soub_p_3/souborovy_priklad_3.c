#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main(){
    char blud[5][5] = {
        "XXXXX",
        "X   X",
        "X   X",
        "X   X",
        "XXXXX"
    };
    int velikost = sizeof(blud[1]);
    for(int i = 0; i<velikost; i++){
        for(int j; j<velikost; j++){
            printf("%c", blud[i][j]);
        }
        printf("\n");
    }
    Sleep(10000);
}