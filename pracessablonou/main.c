#include <stdio.h>
#include <string.h>

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int readInt(char prompt[]) {
    int x;
    int control;
    while (1) {
        printf("%s", prompt);
        control = scanf("%d", &x);
        if (control == 1) {
            cleanBuffer();
            break;
        } else {
            printf("Neplatny vstup zkus to znovu\n");
            cleanBuffer();
        }
    }
    return x;
}

void readString(char str[], int maxLen, char prompt[]) {
    printf("%s", prompt);
    if (fgets(str, maxLen, stdin) == NULL) {
        str[0] = '\0';
        return;
    }
    int pozice = strcspn(str, "\n");
    if (str[pozice] == '\n') {
        str[pozice] = '\0';
    } else {
        cleanBuffer();
    }
}

void vypis_menu(){
    printf("\n--- MENU ---\n");
    printf("1) Soucet pole\n");
    printf("2) Vypis double\n");
    printf("3) Moznost C\n");
    printf("0) Konec\n");
}

void fce_A(int pole[], int velikost){
    int x = 0;
    for(int i = 0; i < velikost; i++){
        x += pole[i];
    }
    printf("soucet: %i\n", x);
}

void fceB(double pole[], int velikost){
    for(int i = 0; i < velikost; i++){
        printf("%.2lf ", pole[i]);
    }
    printf("\n");
}

void fcec(){

}

int main() {
    int volba = 0;
    int pole1[] = {1, 2, 3, 4, 5, 6, 7};
    double platy2[] = {8.9, 9.8, 8.9};
    char pismena3[] = {'a', 'h', 'b'};

    do {
        vypis_menu();
        volba = readInt("Zadej volbu: ");

        if (volba == 1) {
            fce_A(pole1, sizeof(pole1)/sizeof(pole1[0]));
        }
        else if (volba == 2) {
            fceB(platy2, sizeof(platy2)/sizeof(platy2[0]));
        }
        else if (volba == 3) {
            // TODO: moznost C
        }
        else if (volba != 0) {
            printf("Neplatna volba\n");
        }

    } while (volba != 0);

    return 0;
}