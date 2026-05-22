#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int main(){

    
}