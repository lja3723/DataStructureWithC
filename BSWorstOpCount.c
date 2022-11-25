#include "chapter01.h"
#include <stdio.h>

//p.039
int BSearch_p039(int ar[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;
	int opCount = 0; //�񱳿����� Ƚ���� ���

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid])
			return mid;
		else if (target < ar[mid])
			last = mid - 1;
		else
			first = mid + 1;
		opCount++;
	}
	printf("�񱳿���Ƚ��: %d\n", opCount);
	return -1;
}