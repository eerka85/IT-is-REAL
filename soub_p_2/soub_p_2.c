#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

void gen_rand_int_arr(int arr[], int velikost){
    for(int i = 0; i< velikost; i++){
        arr[i] = rand() % 9;
    }
}
void printf_int_arr(int arr[], int velikost){
    printf("\ntisk pole:\n");
    for(int i = 0; i< velikost; i++){
        printf("%d\n", arr[i]);
    }
    printf("\nKONEC tisk pole\n");
}
int fprint_sud_lich_arr(int arr[], int velikost){
    //dva file pointer
    FILE * lich_soub = fopen("C:/Users/Honza Stehlik/Desktop/IT is REAL/soub_p_2/lich_soub.txt", "w");
    FILE * sud_soub = fopen("C:/Users/Honza Stehlik/Desktop/IT is REAL/soub_p_2/sud_soub.txt", "w");
    if(lich_soub == NULL || sud_soub == NULL){
        perror("chyby v otvirani souboru :(");
        return 1;
    }
    //if (pole[i] %2 == 1) tak fprintf(lichej file pointer, %d) 
    for(int i = 0; i<velikost; i++){
        if(arr[i] %2 == 1){
            fprintf(lich_soub,"%d", arr[i]);
        }
        else{
            fprintf(sud_soub,"%d", arr[i]);
        }
    }
    fclose(lich_soub);
    fclose(sud_soub);
    return 0;
}
int main(){
    srand(time(0));
    int velikost = 10;
    int arr[velikost];
    int control = 0;

    gen_rand_int_arr(arr, velikost);
    printf_int_arr(arr, velikost);

    control = fprint_sud_lich_arr(arr, velikost);
    if(control != 0){
        perror("fprint_sud a lich se nepovedlo");
        return 1;
    }
    

    return 0;
}