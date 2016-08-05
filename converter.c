#include <string.h>

#include "converter.h"

char numerals[5] = {'I', 'V', 'X', 'C', 'M'};
int integers[5] = {1, 5, 10, 100, 1000};

int convert(char *numeral) {

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

int index_of(const char *value, const char find) {
	const char *first = strchr(value, find);
	if(first) {
		return first - value;
	} else {
		return -1;
	}
}
