#include <stdlib.h>
#include <stdio.h>
void clean_buffer() {
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
			printf( "\n ##failed to load number##" );
			continue;
		}
		else {
			return tmp;
		}
	}
}
int main(){
    int * pole = malloc(1 * sizeof(int));
    int a = 0;
    if(pole == NULL){
        perror("tak jsi kokot");
    }
    while(1){
        printf("\n1 = dat do pole a tisk\n0 = konec\nvolba: ");
        int volba = input_int(0,1);
        switch (volba){
            case 0:
                free(pole);
                exit(0);
            break;
            case 1:
                printf("\nzadej hodontu: ");
                *(pole + a) = input_int(0, INT_MAX);

                printf("\ntisk pole\n");
                for(int i = 0; i<a+1; i++){
                    printf("%d\n", *(pole + i));
                }
                printf("\nvelikost pole: %d\n", a+1);

                int * tmp = realloc(pole, 1 * sizeof(int));
                if(tmp == NULL){
                    perror("ty jses kokot");
                    exit(0);
                }
                pole = tmp;
                
                a++;
            break;
            
            default:
            break;
        }


    }
    free(pole);
    pole = NULL;

}