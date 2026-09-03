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
    printf("1) Moznost A\n");
    printf("2) Moznost B\n");
    printf("3) Moznost C\n");
    printf("0) Konec\n");
}

int main() {
    int volba = 0;

    do {
        vypis_menu();
        volba = readInt("Zadej volbu: ");

        if (volba == 1) {
            // TODO: moznost A
        }
        else if (volba == 2) {
            // TODO: moznost B
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