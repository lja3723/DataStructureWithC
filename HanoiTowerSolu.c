#include "chapter02.h"
#include <stdio.h>

//p.071
void HanoiTowerMove(int num, char from, char by, char to) {
	if (num == 1)
		printf("원반 1을 %c에서 %c로 이동 \n", from, to);
	else {
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반 %d을(를) %c에서 %c로 이동 \n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}