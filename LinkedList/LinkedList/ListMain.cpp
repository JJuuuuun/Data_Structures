#include <stdio.h>
#include "ArrayList.h"

int main()
{
	// ArrayList 생성 및 초기화
	List list;
	int data;
	ListInit(&list);

	// 데이터 저장
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

/*
	for (int i = 0; i < 101; i++)
		LInsert(&list, 11 * i);
*/

	// 저장된 데이터 전체 출력
	printf("현재 저장된 데이터의 수 : %d\n", LCount(&list));

	// 첫 번쨰 데이터 조회
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
	// 두 번째 데이터 조회
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	// 데이터 22를 모두 삭제
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

	// 삭제후 남은 데이터 출력 
	printf("현재 데이터 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
		
	}

	printf("\n\n");

	return 0;

}