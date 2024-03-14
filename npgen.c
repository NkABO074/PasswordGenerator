#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define CHAR_SET  "abcdefghijkmnopqrstuvwxyz ABCDEFGHIJKMNOPQRSTUVWXYZ-+*/=)([]{}|`#~&^$*!:;,.\?"

/**
 * Generate a pseudo-random password
 * @param n numerical expresion (size of the password)
 * @retrun return the generated password 
 */
char* password(int n) 
{

	if ( n < 4 ) {
        n = 4;
    } else if ( n > 32 ) {
        n = 32;
    }

	int char_set_index = strlen(CHAR_SET) - 1;

	//dynamicly allocate the size of the string acording to the size of the password
	char *pswrd = (char*)malloc((n + 1) * sizeof(char));
	
	//Catch the memory allocation error
	if ( pswrd == NULL ) {
		fprintf(stderr, "memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for ( int i = 0; i < n;i++ ) {
		pswrd[i] = CHAR_SET[rand() % char_set_index];
	}
	
	pswrd[n] = '\0';

	return pswrd;

}


int main(int argc, char* argv[])
{
	// If none args is given, throw a message and exit the programm
	if (argc != 2) {
	    fprintf(stderr, "Usage: %s <password_length>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// convert the argument to integer
	int passwordLength = atoi(argv[1]);

	// initialise the "Seed"
	srand((unsigned int)time(NULL));

	char *generatedPassword = password(passwordLength);
	printf("%s\n", generatedPassword);

	free(generatedPassword);
	
	return 0;
	
}
