#include "ArrayList.h"
#include <stdio.h>
#include <memory.h>

void ListInit(List* plist) {
	plist->numOfData = 0; //저장된 데이터 개수는 0
	plist->curPosition = -1; //아무위치도 가르키지 않음
}
void LInsert(List* plist, LData data) {
	if (plist->numOfData >= LIST_LEN) {
		puts("저장이 불가능합니다.");
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
		puts("삭제할 데이터가 없습니다.");
		return rdata;
	}

	rdata = plist->arr[rpos]; //삭제할 데이터 임시저장

	//삭제를 위한 데이터의 이동을 진행하는 반복문
	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}
int LCount(List* plist) {
	return plist->numOfData;
}