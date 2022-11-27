#include "ArrayList.h"
#include <stdio.h>
#include <memory.h>

void ListInit(List* plist) {
	plist->numOfData = 0; //����� ������ ������ 0
	plist->curPosition = -1; //�ƹ���ġ�� ����Ű�� ����
}
void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN) {
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0)
		return FALSE;

	plist->curPosition = 0;
	*pdata = plist->arr[0];
	return TRUE;
}
int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= plist->numOfData - 1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata;
	memset(&rdata, 0, sizeof(LData));

	if (rpos < 0) {
		puts("������ �����Ͱ� �����ϴ�.");
		return rdata;
	}

	rdata = plist->arr[rpos]; //������ ������ �ӽ�����

	//������ ���� �������� �̵��� �����ϴ� �ݺ���
	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
int LCount(List* plist) {
	return plist->numOfData;
}