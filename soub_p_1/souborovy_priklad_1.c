#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct{
    char jmeno[20];
    char prijmeni[20];
    int vek;
}uzivatel;
void clean_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF){}
}
int input_string(char nacteny_str[], char vypis[]){
    while(1){
        printf("%s", vypis);
        if (fgets(nacteny_str, 10, stdin) == NULL){
            printf("\n spatne nahrany string");
            continue;
        }
        break;
    }
    int pozice = strcspn(nacteny_str, "\n");
    if(nacteny_str[pozice] == '\n'){
        nacteny_str[pozice] = '\0';
    }
    else{
        clean_buffer();
    }
    return 0;
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
void menu(){
    printf("\n====MENU====");
    printf("\n0 - konec");
    printf("\n1 - zalozeni uzivatele");
    printf("\n2 - tisk souboru");
}
int pis_do_soub(uzivatel cislo){
    FILE * soubor = fopen("C:/Users/Honza Stehlik/Desktop/IT is REAL/data.txt", "a+");
    if(soubor == NULL){
        return 1;
    }
    fprintf(soubor, "%s;%s;%d\n", cislo.jmeno, cislo.prijmeni, cislo.vek);
    fclose(soubor);
    return 0;
}
int tisk_soub(){
    char radek[60];
    int u = 0;
    printf("\n\n%%%%%%%% TISK SOUBORU %%%%%%%%\n");
    FILE * soubor = fopen("C:/Users/Honza Stehlik/Desktop/IT is REAL/soub_p_1/data.txt", "r");
    if(soubor == NULL){
        return 1;
    }

    while(fgets(radek, 60, soubor) != NULL){
        char* blabla = strtok(radek, ";");

        printf("\nUzivatel %d:\nJmeno: %s",u ,blabla);
        blabla = strtok(NULL, ";");
        
        printf("\nPrijmeni: %s", blabla);
        blabla = strtok(NULL, ";");

        printf("\nVek: %s", blabla);

        u++;
    }
    fclose(soubor);
    printf("\n");
    return 0;
}
int main(){
    int volba = 0;
    int control = 0;
    //char cislo[20];
    while(1){
        menu();
        volba = input_int(0,2,"\ntvoje volba: ");
        switch(volba){
            case 0:
                Sleep(500);
                return 0;
            break;
            case 1:
                //input_string(cislo, "\nnapis nazev uzivatele: ");
                uzivatel cislo;
                input_string(cislo.jmeno, "\nnapis jmeno: ");
                input_string(cislo.prijmeni, "\nnapis prijmeni: ");
                cislo.vek = input_int(0, 120, "\nnapis vek: ");

                control = pis_do_soub(cislo);
                if(control != 0){
                    perror("chyba v pis_do_soub");
                }
            break;
            case 2:
                 control = tisk_soub();
                  if(control != 0){
                    perror("chyba v tisk_soub");
                }
            break;
        }
    }
    return 0;
}