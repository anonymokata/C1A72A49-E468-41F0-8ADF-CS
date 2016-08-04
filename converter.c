#include <string.h>

#include "converter.h"

int convert(char *numeral) {
	int returnInteger = 1;

	int v_index = index_of(numeral, 'V');

	if(v_index != -1) {
		returnInteger = 5;
		int i_index = index_of(numeral, 'I');
		if((i_index >= 0) && (i_index < v_index)) {
			returnInteger = 4;
		}
	}

	if(strcmp(numeral, "II") == 0) {
		returnInteger = 2;
	} else if(strcmp(numeral, "III") == 0) {
		returnInteger = 3;
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