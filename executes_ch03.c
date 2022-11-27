#include "executes_ch03.h"
#include "chapter03.h"
#include <stdio.h>
#include <string.h>

//두번째 파라미터를 읽어온다
int getSecondParam(char* cmd, int* iFirst, int* iLast) {
	int data = 0;
	if (cmd == NULL || iFirst == NULL || iLast == NULL)
		return data;

	*iFirst = ++(*iLast);
	while (*iLast < 255 &&
		cmd[*iLast] != 0 &&
		cmd[*iLast] != ' ') {
		data *= 10;
		data += cmd[(*iLast)++] - '0';
	}
	cmd[(*iLast)] = 0;

	return data;
}

void execute_ch03_p081()
{
	// ArrayList의 생성 및 초기화 ///
	List list;
	int data;
	ListInit(&list);

	// 5개의 데이터 저장 ///
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	// 저장된 데이터의 전체 출력 ///
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	//첫 번째 데이터 조회
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) //두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");

	// 숫자 22를 탐색하여 모두 제거 ///
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data == 22)
				LRemove(&list);
	}

	// 삭제 후 남은 데이터 전체 출력 ///
	printf("현재 데이터의 수 : %d \n", LCount(&list));

	//첫 번째 데이터 조회
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) //두 번째 이후의 데이터 조회
			printf("%d ", data);
	}
	printf("\n\n");
}
void execute_ch03_p085_Q03_1() {
	List list;
	ListInit(&list);

	int i;
	for (i = 1; i < 10; i++)
		LInsert(&list, i);

	int data, sum = 0;
	if (LFirst(&list, &data)) {
		sum += data;
		while (LNext(&list, &data))
			sum += data;
	}
	printf("1부터 9까지의 합: %d\n", sum);

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
	}

	printf("2의 배수와 3의 배수를 제거한 10 이하의 자연수 리스트:\n");
	if (LFirst(&list, &data)) {
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
}
void execute_ch03_p085_MyTest() {
	List list;
	ListInit(&list);

	while (1) {
		char cmd[256] = { 0 };
		int szbuff = sizeof(cmd) / sizeof(char);

		printf("> ");
		gets_s(cmd, szbuff);
		int iFirst = 0, iLast = 0;
		while (iLast < 255 && 
			cmd[iLast] != 0 && 
			cmd[iLast] != ' ') iLast++;
		cmd[iLast] = 0;

		if (!strcmp(cmd, "exit")) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		else if (!strcmp(cmd, "count")) {
			printf("리스트 크기: %d\n", LCount(&list));
		}
		else if (!strcmp(cmd, "insert")) {
			//두 번째 파라미터 읽어오기
			int data = getSecondParam(cmd, &iFirst, &iLast);

			LInsert(&list, data);
			printf("데이터 %d이(가) 삽입되었습니다.\n", data);
		}
		else if (!strcmp(cmd, "print")) {
			int data;
			if (LFirst(&list, &data)) {
				printf("%d ", data);
				while (LNext(&list, &data))
					printf("%d ", data);
				printf("\n");
			}
		}
		else if (!strcmp(cmd, "remove_first")) {
			LData data;
			if (LFirst(&list, &data))
				LRemove(&list);
		}
		puts("");
	}
}
