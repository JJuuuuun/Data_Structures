#include <stdio.h>
#include "ArrayList.h"


void ListInit(List * plist)
{
	plist->numOfData = 0;					// ����� ������ ���� 0���� �ʱ�ȭ
	plist->curPosition = -1;				// ���� ����Ű�� ���� ����
}

void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)		// ����� ������ �迭���̺��� ũ�ٸ� ����
	{
		puts("������ �Ұ����մϴ�.");
		return;
	}

	plist->arr[plist->numOfData] = data;	// ������ ����
	plist->numOfData++;						// ����� ������ ���� ����
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)				// ����� �����Ͱ� ���ٸ� ����
		return FALSE;

	plist->curPosition = 0;					// ���� ��ġ �ʱ�ȭ
	*pdata = plist->arr[0];					// pdata�� ����Ű�� ������ ������ ����
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= plist->numOfData - 1)		// ������ �����Ͱ� ���ٸ�
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