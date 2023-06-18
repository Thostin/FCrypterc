#include "functions.c"

char *load_file(char *file_name, int *elem); //Load the file into an array
char *g_pswrd(void); //Get the password
FILE *crypt(char *pswrd, char *file, char *file_name); //Crypt the file

