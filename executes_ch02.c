#include "executes_ch02.h"
#include "chapter02.h"
#include <stdio.h>

void execute_ch02_p055()
{
	printf("1! = %d\n", Factorial(1));
	printf("2! = %d\n", Factorial(2));
	printf("3! = %d\n", Factorial(3));
	printf("4! = %d\n", Factorial(4));
	printf("9! = %d\n", Factorial(9));
}
void execute_ch02_p057() {
	int i;
	for (i = 1; i < 15; i++)
		printf("%d ", Fibo(i));
}
void execute_ch02_p063() {
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);

	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);

	idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스: %d\n", idx);
}
void execute_ch02_p071() {
	//막대 A의 원반 3개를 막대 B를 경우하여 막대 C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');
}