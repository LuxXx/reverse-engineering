#define GENERATEKEY 1 // 1 for keygen, 0 for keygenme
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* generateKey(char* name) {
	char data[] = { 0x13, 0x37, 0xDE, 0xAD, 0xC0, 0xDE };
	char alphabet[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 36 for the alphabet + one for \0

	char *key;
	key = (char*) malloc(16 + 1); // allocate 16 chars and one for the \0
	for (int n = 0; n < 16; n++) // sanitize the memory with exclamation marks ^^
		key[n]= 33; // 33 is the exclamation mark
	key[16]='\0';

	for (int i = 0; i < 16; i++)
	{
		int chosenDataValue = data[i % 6];
		int nameVal = 2 * (name[i % strlen(name)] + 0xBEEF);
		int k = chosenDataValue + nameVal + i;
		
		int mod = k % 36;
		
		key[i] = alphabet[mod];
	}
	return key;
}

int main() {

	printf("KeyGenMe Two by LuxXx - https://github.com/LuxXx/reverse-engineering\n");
	
	char* username;
	username = (char*) malloc(16 + 1);
	username[16] = '\0';
	printf("Enter username: ");
	scanf("%s16", username);
	
	#if (GENERATEKEY != 1)
	char* serial;
	serial = (char*) malloc(16 + 1);
	serial[16] = '\0';
	printf("Enter serial: ");
	scanf("%s16", serial);
	
	if (!strcmp(serial, generateKey(username))) {
		printf("Awesome, write a KeyGen\n");
	} else {
		printf("Try harder!\n");
	}
	#endif
	
	#if (GENERATEKEY == 1)
	printf("Serial: %s\n", generateKey(username));
	#endif
	
	getchar();
	getchar();
	return 1;
}