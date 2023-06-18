#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));

	for(int i = 0; i < 100; i++)
		printf("%i. %i\n", i, rand() % 5);
	return 0;
}

