#include <stdio.h>
#include <windows.h> 
#include <mmsystem.h> 
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

 

int main() 

{ 

    int i = input_int(0,2); 

    switch (i)
    {
    case 0:
        PlaySound("C:/Users/Honza Stehlik/Desktop/IT-is-REAL/audiovC/Alert.wav", NULL, SND_FILENAME | SND_SYNC);
    break;

    case 1:
        PlaySound("C:/Users/Honza Stehlik/Desktop/IT-is-REAL/audiovC/aehm.wav", NULL, SND_FILENAME | SND_SYNC);
    break;

    case 2:
        PlaySound("C:/Users/Honza Stehlik/Desktop/IT-is-REAL/audiovC/Lasershot.wav", NULL, SND_FILENAME | SND_SYNC);
    break;
    
    default:
    break;
    }

 

    

 

    return 0; 

} 