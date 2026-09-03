%:include <stdio.h>
%:include <stdlib.h>

int main()<% int input; do<% printf("input number: "); if((scanf("%i", &input)) != 1) return 1; if(input == 0) return 0; if(input == 1) printf("1\n"); if(input == 2) printf("2\n"); %> while(input != 0); return 0; %>