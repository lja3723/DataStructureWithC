#include "chapter01.h"

//p.019
int LSearch(int ar[], int len, int target)
{
	int i;
	for (i = 0; i < len; i++)
		if (ar[i] == target)
			return i;

	return -1;
}