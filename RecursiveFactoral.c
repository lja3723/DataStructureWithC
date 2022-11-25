#include "chapter02.h"

//p.055
int Factorial(int n) {
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}
