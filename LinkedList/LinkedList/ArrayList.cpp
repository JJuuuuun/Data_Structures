#include <stdio.h>
#include "ArrayList.h"


void ListInit(List * plist)
{
	plist->numOfData = 0;					// 저장된 데이터 개수 0으로 초기화
	plist->curPosition = -1;				// 현재 가르키는 곳은 없다
}

void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)		// 저장된 개수가 배열길이보다 크다면 리턴
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data;	// 데이터 저장
	plist->numOfData++;						// 저장된 데이터 개수 증가
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)				// 저장된 데이터가 없다면 리턴
		return FALSE;

	plist->curPosition = 0;					// 참조 위치 초기화
	*pdata = plist->arr[0];					// pdata가 가르키는 공간에 데이터 저장
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)		// 참조할 데이터가 없다면
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}