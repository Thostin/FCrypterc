/*
 * Ojala que Ryoma y Daichi esten leyendo esto
 */

#include "functions.h"

#define nullptr 0X00000000
#define FILE_NAME_SIZE 100
int main(void){

	char file_name[FILE_NAME_SIZE];
	printf("Write the name of the file: ");
	scanf("%s", file_name);

	int elem;
	char *file = load_file(file_name, &elem);

	srand(time(NULL));
	char *password = g_pswrd();

	FILE *crypted_file = crypt(password, file, file_name);

	printf("\"%s\" was created \nSIZE: %iB\n\n", file_name, elem);
	printf("This is the random generated password: \n%s\n\n", password);

	fflush(crypted_file);
	fclose(crypted_file);

	// Create a file to store the password
	strcat(file_name, ".password.txt");
	FILE *PASSWORD_FILE = fopen(file_name, "w");

	fputs(password, PASSWORD_FILE);

	fflush(PASSWORD_FILE);
	fclose(PASSWORD_FILE);

	return 0;
}

