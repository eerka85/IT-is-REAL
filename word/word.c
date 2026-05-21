#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
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
int soub_uprava(char nazev_soub[]){
    char adresa_soub[] = {"C:/Users/Honza Stehlik/Desktop/IT is REAL/word/", "a+"};
    char bufiik[256];
    strcat(adresa_soub, nazev_soub);
    FILE * soubor = fopen(adresa_soub, "a+");
    if(soubor == NULL){
        return 1;
    }
    while(1){
        //tisk celyho souboriku
        while(fgets(bufiik, sizeof(bufiik), soubor) != NULL){
            
        }





    }
    fclose(soubor);
    return 0;
}
int main(){
    int velikost = 20;
    char nazev_soub[velikost];
    input_string(nazev_soub, "napis jmeno souborru pro otevreni: ");
    strcat(nazev_soub, ".txt");
    int control = soub_uprava(nazev_soub);
    if(control != 0){
        perror("chyba v soubor_uprava");
        return 1;
    }

    return 0;
}