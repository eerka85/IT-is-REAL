#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"


int kets(){
    int klavesa = _getch();
    if(klavesa == 0 || klavesa == 224){
        klavesa = _getch();
        klavesa += 1000;
    }
    return klavesa;
}
void clear_screen_CONTINUE(){
	printf(BLUE "\n CONTINUE? (press enter)" RESET);
	getchar();
	system("cls");
}

void del_screen_cursor(){
	COORD cursorPosition;// ts is highkey ai
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

typedef enum {
    STAV_MENU,
    STAV_CRAFT,
    STAV_MINE,
    STAV_FIGHT,
    STAV_BOSS,
    STAV_KONEC
} Stav;

void print_menu(int poz_vmenu, int pocet_polozek, char menu_pis[pocet_polozek-1][20]){
    for(int i = 0; i< pocet_polozek; i++){
        printf("%s %s\n", i == poz_vmenu ? "->" : "  ", menu_pis[i]);
    }
}

void changepos(int *poz_vmenu, Stav * aktualnistav){
    int klavesa = kets();
    switch(klavesa){
        case 1072:
            if(*poz_vmenu == 0){
                *poz_vmenu = 4;
            }
            else{
                (*poz_vmenu)--;
            }
        break;

        case 1080:
            if(*poz_vmenu == 4){
                *poz_vmenu = 0;
            }
            else{
                (*poz_vmenu)++;
            }
        break;

        case 13:
            switch(*poz_vmenu){
                case 0:
                    *aktualnistav = STAV_CRAFT;
                break;

                case 1:
                    *aktualnistav = STAV_MINE;
                break;

                case 2:
                    *aktualnistav = STAV_FIGHT;
                break;

                case 3:
                    *aktualnistav = STAV_BOSS;
                break;

                case 4:
                    *aktualnistav = STAV_KONEC;
                break;      
            }
        break;
    }
}

int main(){
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);//ai schovani kurzoru
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = FALSE; 
    SetConsoleCursorInfo(out, &cursorInfo);

    int pocet_polozek = 5;
    char menu_pis[pocet_polozek][20];
    strcpy(menu_pis[0], "craft");
    strcpy(menu_pis[1], "mine");
    strcpy(menu_pis[2], "fight");
    strcpy(menu_pis[3], "boss");
    strcpy(menu_pis[4], "konec");

    Stav aktualnistav = STAV_MENU;
    int poz_vmenu = 0;


    system("cls");
    while(aktualnistav != STAV_KONEC){
        switch(aktualnistav){
            case STAV_MENU:
                print_menu(poz_vmenu, pocet_polozek, menu_pis);
                changepos(&poz_vmenu, &aktualnistav);
                del_screen_cursor();
            break;

            case STAV_CRAFT:
                system("cls");
                printf(" craft");
                aktualnistav = STAV_MENU;
                clear_screen_CONTINUE();
            break;

            case STAV_MINE:
                system("cls");
                printf(" mine");
                aktualnistav = STAV_MENU;
                clear_screen_CONTINUE();
            break;

            case STAV_FIGHT:
                system("cls");
                printf(" fight");
                aktualnistav = STAV_MENU;
                clear_screen_CONTINUE();
            break;

            case STAV_BOSS:
                system("cls");
                printf(" boss");
                aktualnistav = STAV_MENU;
                clear_screen_CONTINUE();
            break;

            default:
            break;          
        }
    }
    system("cls");
    return 0;
}