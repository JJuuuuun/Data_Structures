#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
	int mid;

	if (first > last)
		return -1;

	mid = (first + last) / 2;
	if (ar[mid] == target)
		return mid;
	else if (ar[mid] > target)
		return BSearchRecur(ar, first, mid - 1, target);
	else
		return BSearchRecur(ar, mid + 1, last, target);

}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int first = 0; 
	int last = sizeof(arr) / sizeof(int) - 1;
	int idx;

	idx = BSearchRecur(arr, first, last, 5);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÁöÁ¤ ÀÎµ¦½º : %d\n", idx);

	idx = BSearchRecur(arr, first, last, 0);
	if (idx == -1)
		printf("Å½»ö ½ÇÆĞ\n");
	else
		printf("Å¸°Ù ÁöÁ¤ ÀÎµ¦½º : %d\n", idx);

}