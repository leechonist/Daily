#include <stdio.h>
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int Selection(int*, int, int, int);
void main()
{
	int key = 1;
	int arr[12] = { 6,3,11,9,12,2,8,15,18,10,7,14 };
	printf("%d번째로 작은 수 : %d",key, Selection(arr, 0, (sizeof(arr)/sizeof(int))-1, key-1));
}
int Selection(int* aArray, int aStart, int aEnd, int aKey)
{
	int pivot = (aStart+aEnd)/2;
	int l = aStart, r = aEnd;
	swap(&aArray[pivot], &aArray[aStart]);
	pivot = aStart;
	while (l < r)
	{
		while ((l < aEnd)&&(aArray[l] < aArray[pivot])) l++;
		while((r > aStart) && (aArray[r] > aArray[pivot])) r--;
		if (aArray[l] > aArray[r]) swap(&aArray[l], &aArray[r]);
	}
	
	swap(&aArray[l], &aArray[pivot]);
	pivot = l;

	if (pivot == aKey) return aArray[pivot];
	if (pivot > aKey) return Selection(aArray, aStart, pivot - 1, aKey);
	else if (pivot < aKey) return Selection(aArray, pivot + 1, aEnd, aKey);
}
