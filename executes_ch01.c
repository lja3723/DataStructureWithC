#include "executes_ch01.h"
#include "chapter01.h"
#include <stdio.h>

void execute_ch01_p019() {
	int arr[] = { 3, 5, 2, 4, 9 };

	int idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);
}
void execute_ch01_p028() {
	int arr[] = {1, 3, 5, 7, 9};
	int idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);
}
void execute_ch01_p039() {
	int arr1[500] = { 0 };
	int arr2[5000] = { 0 };
	int arr3[50000] = { 0 };
	int idx;
	
	//배열 arr1을 대상으로 저장되지 않은 정수를 찾으라고 명령
	idx = BSearch_p039(arr1, sizeof(arr1) / sizeof(int), 1);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	//배열 arr2을 대상으로 저장되지 않은 정수를 찾으라고 명령
	idx = BSearch_p039(arr2, sizeof(arr2) / sizeof(int), 2);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	//배열 arr3을 대상으로 저장되지 않은 정수를 찾으라고 명령
	idx = BSearch_p039(arr3, sizeof(arr3) / sizeof(int), 3);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);
}
