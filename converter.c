#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "converter.h"

char numerals[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int integers[7] = {1, 5, 10, 50, 100, 500, 1000};

int to_roman_integers[6] = {500, 100, 50, 10 ,5, 1};
char to_roman_characters[6] = {'D', 'C', 'L', 'X', 'V', 'I'};

int convert_to_integer(const char *numeral) {

	int previousValue = 0;
	int returnInteger = 0;
	for(int i = (strlen(numeral) - 1); i >= 0; i--) {
		int numeralIndex = index_of(numerals, numeral[i]);
		int integerIndexValue = integers[numeralIndex];

		if(integerIndexValue < previousValue) {
			returnInteger -= integerIndexValue;
		} else {
			returnInteger += integerIndexValue;
		}

		previousValue = integerIndexValue;
	}

	return returnInteger;
}

char *convert_to_numeral(int integer) {
	char *return_buffer = malloc(sizeof(char));

	for(int i = 0; i < (sizeof(to_roman_integers)/sizeof(to_roman_integers[0])); i++) {
	 	while (to_roman_integers[i] <= integer) {
	     	integer -= to_roman_integers[i];
	    	snprintf(return_buffer, sizeof return_buffer, "%s%c", return_buffer, to_roman_characters[i]);
	    }
	}

	char *return_copy = malloc(sizeof(char));
	strcpy(return_copy, return_buffer);
	free(return_buffer);

	return return_copy;
}

int index_of(const char *value, const char find) {
	const char *first = strchr(value, find);
	if(first) {
		return first - value;
	} else {
		return -1;
	}
}
