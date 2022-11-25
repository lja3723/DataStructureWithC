#include "executes_ch01.h"
#include "chapter01.h"
#include <stdio.h>

void execute_ch01_p019() {
	int arr[] = { 3, 5, 2, 4, 9 };

	int idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);
}
void execute_ch01_p028() {
	int arr[] = {1, 3, 5, 7, 9};
	int idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);
}
void execute_ch01_p039() {
	int arr1[500] = { 0 };
	int arr2[5000] = { 0 };
	int arr3[50000] = { 0 };
	int idx;
	
	//�迭 arr1�� ������� ������� ���� ������ ã����� ���
	idx = BSearch_p039(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	//�迭 arr2�� ������� ������� ���� ������ ã����� ���
	idx = BSearch_p039(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);

	//�迭 arr3�� ������� ������� ���� ������ ã����� ���
	idx = BSearch_p039(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε���: %d\n", idx);
}
