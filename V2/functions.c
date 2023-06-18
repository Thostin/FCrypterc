#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

#define nullptr 0X00000000
#define TYPE char
#define TO 126
#define FROM 32

FILE *crypt(char *pswrd, char *file, char *file_name){

	for(int i = 0; file[i] != 0; i++){
                if(file[i] < FROM || file[i] > TO)
                        continue;
                file[i] = pswrd[file[i] - FROM];
        }

	strcat(file_name, ".crypt");
	FILE *crypt_file = fopen(file_name, "wb");

	fputs(file, crypt_file);
	return crypt_file;
}

char *g_pswrd(void){
	// #define TYPE char
	TYPE *password = (TYPE *)malloc(TO - FROM + 1);
	for(int i = 0; i <= TO - FROM; i++)
		password[i]= '\0';

	int y;
	for(TYPE i = FROM; i <= TO; ++i){
		y = rand()%(TO - FROM + 1);
		if(password[y] == '\0')
			password[y] = (TYPE)i;
		else
			--i;
	}

	return password;
}

char *load_file(char *file_name, int *elem){

        FILE *flow = fopen(file_name, "r");

        if(flow == nullptr){
                perror("Error al abrir el archivo");
                return nullptr;
        }

        fseek(flow, 0, SEEK_END);
        *elem = ftell(flow);
        char *file = (char *)malloc(*elem);

        rewind(flow);
        fread(file, 1, *elem, flow);

        fflush(flow);
        fclose(flow);
	
	return file;
}

