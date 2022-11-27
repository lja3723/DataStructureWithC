#include "executes_ch03.h"
#include "chapter03.h"
#include <stdio.h>
#include <string.h>

//�ι�° �Ķ���͸� �о�´�
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
	// ArrayList�� ���� �� �ʱ�ȭ ///
	List list;
	int data;
	ListInit(&list);

	// 5���� ������ ���� ///
	LInsert(&list, 11);	LInsert(&list, 11);
	LInsert(&list, 22);	LInsert(&list, 22);
	LInsert(&list, 33);

	// ����� �������� ��ü ��� ///
	printf("���� �������� �� : %d \n", LCount(&list));

	//ù ��° ������ ��ȸ
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) //�� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	// ���� 22�� Ž���Ͽ� ��� ���� ///
	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data == 22)
				LRemove(&list);
	}

	// ���� �� ���� ������ ��ü ��� ///
	printf("���� �������� �� : %d \n", LCount(&list));

	//ù ��° ������ ��ȸ
	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data)) //�� ��° ������ ������ ��ȸ
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
	printf("1���� 9������ ��: %d\n", sum);

	if (LFirst(&list, &data)) {
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
	}

	printf("2�� ����� 3�� ����� ������ 10 ������ �ڿ��� ����Ʈ:\n");
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
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		else if (!strcmp(cmd, "count")) {
			printf("����Ʈ ũ��: %d\n", LCount(&list));
		}
		else if (!strcmp(cmd, "insert")) {
			//�� ��° �Ķ���� �о����
			int data = getSecondParam(cmd, &iFirst, &iLast);

			LInsert(&list, data);
			printf("������ %d��(��) ���ԵǾ����ϴ�.\n", data);
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
