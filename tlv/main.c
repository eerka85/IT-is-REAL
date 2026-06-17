#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED     "\x1b[31m"
#define BLUE    "\x1b[34m"
#define RESET   "\x1b[0m"

void clean_buffer();
void clear_screen_CONTINUE();
int input_int(int min, int max);
int input_string(char nacteny_str[], int velikost, char vypis[]);
void exit_my();

int main(){
    char main_buffer[1024];
    char * inputed_cmd_tok;
    char * inputed_key_tok;
    char * inputed_type_tok;
    char * inputed_value_tok;
    int value_lenght = 0;
    int * key_rn;
    while(1){
        input_string(main_buffer, sizeof(main_buffer), "==TLV HELP==\nfirst write command: init/check/write THEN SPACE\nif using init skip this (second write your key (you will use this to acces data) THEN SPACE)\nif using init or write (third write type: int/double/string THEN ;\nforth ou write the value)  WRITE: ");
        inputed_cmd_tok = strtok(main_buffer, " ");
        if(strcmp(inputed_cmd_tok, "init") == 0){
            inputed_type_tok = strtok(NULL, ";");
            inputed_value_tok = strtok(NULL, "\n");
            value_lenght = strlen(inputed_value_tok);            
            if(strcmp(inputed_type_tok, "int") == 0){
                key_rn = malloc(2 * sizeof(int) + value_lenght * sizeof(char));
                *key_rn = 1;
                *(key_rn +1) = value_lenght;
                int inputed_int = atoi(inputed_value_tok);
                *(key_rn +2) = inputed_int;

            }
            else if(strcmp(inputed_type_tok, "double") == 0){

            }
            else if(strcmp(inputed_type_tok, "string") == 0){

            }
            else{
                printf("type is wrong\n");
            }
        }
        else if(strcmp(inputed_cmd_tok, "check") == 0){
        inputed_key_tok = strtok(NULL, " ");

        }
        else if(strcmp(inputed_cmd_tok, "write") == 0){

        }
        else{
            printf("cmd is wrong\n");
        }
        clear_screen_CONTINUE();
    }
    return 0;
}
void exit_my(){
    exit(0);
}

void clean_buffer(){
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}

int input_int(int min, int max) {
	int tmp = 0;
	while(1) {
		printf("\n CHOOSE: " );
		int is_input_valid = scanf("%d", &tmp);
		clean_buffer();
		if(is_input_valid == 0 || tmp <min || tmp >max) {
			printf(RED "\n ##failed to load number##" RESET);
			continue;
		}
		else {
			return tmp;
		}
	}
}

int input_string(char nacteny_str[], int velikost, char vypis[]){
    while(1){
        printf("%s", vypis);
        if (fgets(nacteny_str, velikost, stdin) == NULL){
            printf("\n ##failed to load string##");
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

void clear_screen_CONTINUE(){
	printf(BLUE "\n CONTINUE? (press enter)" RESET);
	getchar();
	printf("\033[H\033[2J");
}