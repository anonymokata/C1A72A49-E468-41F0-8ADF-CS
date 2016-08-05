#include <string.h>

#include "converter.h"

char numerals[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int integers[7] = {1, 5, 10, 50, 100, 500, 1000};

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

char convert_to_numeral(const int integer) {
	return 'I';
}

int index_of(const char *value, const char find) {
	const char *first = strchr(value, find);
	if(first) {
		return first - value;
	} else {
		return -1;
	}
}
