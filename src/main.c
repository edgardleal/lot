#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "num.h"

int main() 
{
	struct Num* num = newNum();
	int i;
	while(i < 252) 
	{
	    num->print(num);
	    num->inc(num);
	    i = i + 1;
	}

	free(num);

	return 0;
}
