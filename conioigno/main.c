#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h> 
#include <mmsystem.h> 

int main(){
    bool is_prefix = false;
    while(1){
        is_prefix = false;
        int input = _getch();
        if(input == 0 || input == 224){
            input = _getch();
            is_prefix = true;
        }
        printf("znak %c cislo %d is prefix %s\n", input, input, is_prefix ? "true" : "false");
        if(input == 72 && is_prefix){
            PlaySound("aehm.wav", NULL, SND_FILENAME | SND_SYNC);
        }
        if(input == 80 && is_prefix){
            PlaySound("Alert.wav", NULL, SND_FILENAME | SND_SYNC);
        }
    }
    return 0;
}