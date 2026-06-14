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
    int inputed_key = 0;
    char * inputed_type_tok;
    char * inputed_value_tok;
    while(1){
        input_string(main_buffer, sizeof(main_buffer), "==TLV HELP==\nfirst write command: init/check/write THEN SPACE\nsecond write your key (you will use this to acces data) THEN SPACE\nif using init or write (third write type: int/double/string THEN ;\nforth ou write the value)  WRITE: ");
        inputed_cmd_tok = strtok(main_buffer, " ");
        inputed_key_tok = strtok(NULL, " ");
        inputed_key = atoi(inputed_key_tok);

        if(strcmmp(inputed_cmd_tok, "init") == 0){

        }
        else if(strcmmp(inputed_cmd_tok, "check") == 0){

        }
        else if(strcmmp(inputed_cmd_tok, "write") == 0){

        }
        else{
            printf("cmd is wrong");
        }
        clear_screen_CONTINUE();
    }
    return 0;
}
void exit_my(){
    exit(0);
}

int write_tlv(){
    char main_buffer[1024] = {0};
    char * inputed_type_tok;
    char * inputed_value_tok;

    input_string(main_buffer, sizeof(main_buffer), " ===TLV CREATION===\n "); 

    inputed_type_tok = strtok(main_buffer, ";");
    if(strcmp(inputed_type_tok, "01") == 0){
        printf(" JEDNICKAAA\n");
    }
    else if(strcmp(inputed_type_tok, "02") == 0){
        printf(" DVAAAAAAAAAA\n");
    }
    else if(strcmp(inputed_type_tok, "03") == 0){
        printf(" TRIIIIIIIII\n");
    }
    else{
        printf(" ##couldnt recognize type##\n");
        return 1;
    }

    

    return 0;
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