#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

int ascii_check(char str[]) {
    int i = 0;
    while(str[i] !='\0') {
        if((unsigned char) str[i] > 127) return 0;
        i++;
    }
    return 1;
}

void ascii_capitalize(char str[]) {
	int i =0;
	while(str[i] != '\0') {
		if(str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ('a' -'A');
		}
		i ++;
	}
}


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: utf8analyzer \"<UTF-8 encoded string>\"\n");
        return 1;
    }
    char input[2048];
    strncpy(input, argv[1], sizeof(input));
    input[sizeof(input) - 1] = '\0';

    int ascii = ascii_check(input);
    printf("Valid ASCII: %s\n", ascii ? "true" : "false");

    ascii_capitalize(input);
    printf("Uppercasess ACSII: %s\n", input);
}
