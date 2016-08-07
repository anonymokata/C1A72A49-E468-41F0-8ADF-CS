#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "converter.h"

char numerals[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int integers[7] = {1, 5, 10, 50, 100, 500, 1000};

int to_roman_integers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
char *to_roman_characters[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

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
	char *return_buffer = calloc(16, sizeof(char));

	for(int i = 0; i < (sizeof(to_roman_integers)/sizeof(to_roman_integers[0])); i++) {
	 	while (to_roman_integers[i] <= integer) {
	     	integer -= to_roman_integers[i];
	     	strcat(return_buffer, to_roman_characters[i]);
	    }
	}
	char *return_copy = calloc(16, sizeof(return_buffer));
	strcpy(return_copy, return_buffer);
	free(return_buffer);

	return return_copy;
}

char *add(const char *num_one, const char *num_two) {
	int integer_value_one = convert_to_integer(num_one);
	int integer_value_two = convert_to_integer(num_two);
	int total = integer_value_one + integer_value_two;

	char *final_numeral = convert_to_numeral(total);

	return final_numeral;
}

int index_of(const char *value, const char find) {
	const char *first = strchr(value, find);
	if(first) {
		return first - value;
	} else {
		return -1;
	}
}
