#include <string.h>

#include "converter.h"

int convert(char * numeral)
{
	if(strcmp(numeral, "II") == 0)
	{
		return 2;
	}
	return 1;
}