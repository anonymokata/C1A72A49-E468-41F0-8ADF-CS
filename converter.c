#include <string.h>

#include "converter.h"

int convert(char * numeral)
{
	int returnInteger = 1;

	if(strcmp(numeral, "II") == 0)
	{
		returnInteger = 2;
	}
	else if(strcmp(numeral, "III") == 0)
	{
		returnInteger = 3;
	}

	return returnInteger;
}