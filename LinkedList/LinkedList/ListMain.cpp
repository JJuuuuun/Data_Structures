#include <stdio.h>
#include "ArrayList.h"

int main()
{
	// ArrayList ���� �� �ʱ�ȭ
	List list;
	int data;
	ListInit(&list);

	// ������ ����
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

/*
	for (int i = 0; i < 101; i++)
		LInsert(&list, 11 * i);
*/

	// ����� ������ ��ü ���
	printf("���� ����� �������� �� : %d\n", LCount(&list));

	// ù ���� ������ ��ȸ
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
	// �� ��° ������ ��ȸ
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// ������ 22�� ��� ����
	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data == 22)
				LRemove(&list);
		}
	}

	// ������ ���� ������ ��� 
	printf("���� ������ �� : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
		
	}

	printf("\n\n");

	return 0;

}