#include <stdio.h>

int Bsearch(int ar[], int len, int target)
{
	int first = 0, last = len - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (target == ar[mid])
			return mid;			
		else
		{
			if (target < ar[mid])
				last = mid - 1;			
			else
				first = mid + 1;			
		}		
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21 };
	int idx;

	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 13);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	idx = Bsearch(arr, sizeof(arr) / sizeof(int), 23);
	if (idx == -1)
		printf("Ž�� ����\n");
	else
		printf("Ÿ�� ���� �ε��� : %d\n", idx);

	return 0;
}