#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int kresli_do_soub(char blud[5][5], int velikost){
    FILE * soubor = fopen("C:/Users/Honza Stehlik/Desktop/IT is REAL/soub_p_3/data.txt", "w");
    if(soubor == NULL){
        return 1;
    }
    for(int i = 0; i<velikost; i++){
        for(int j = 0; j<velikost; j++){
            fprintf(soubor, "%c", blud[i][j]);
        }
        fprintf(soubor, "\n");
    }
    fclose(soubor);
    return 0;
}
int main(){
    char blud[5][5] = {
        "XXXXX",
        "X   X",
        "X   X",
        "X   X",
        "XXXXX"
    };
    int velikost = sizeof(blud[1]);
    int control = kresli_do_soub(blud, velikost);
    if(control != 0){
        perror("jses fakt pica");
        return 1;
    } 
    
    Sleep(10000);
    return 0;
}