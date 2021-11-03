#include <stdio.h>
#include <math.h>
typedef struct point
{
	int x,y;
}point;
int closetPair1(point*,int);
double ClosetPair2(point*, int, int,int);
point makePoint(int, int);
void main()
{
	point arr[10];
	arr[0] = makePoint(1, 0);
	arr[1] = makePoint(13, 0);
	arr[2] = makePoint(17, 15);
	arr[3] = makePoint(25, 30);
	arr[4] = makePoint(26, 0);
	arr[5] = makePoint(28, 23);
	arr[6] = makePoint(30, 0);
	arr[7] = makePoint(37, 0);
	arr[8] = makePoint(45, 0);
	arr[9] = makePoint(56, 0);

	printf("%d", closetPair1(arr,10));
	return 0;
}
int closetPair1(point* aArr,int aSize)
{
	int mid = aSize/2;
	double min,tmp;
	min = ClosetPair2(aArr, 0, mid - 1,aSize);
	tmp = ClosetPair2(aArr, mid, aSize, aSize);
	min = min < tmp ? min : tmp;

	tmp = ClosetPair2(aArr, mid - (int)min, mid + (int)min,aSize);
	min = min < tmp ? min : tmp;

	return (int)min;
}
double ClosetPair2(point* aArr, int aX1, int aX2,int aSize)
{
	double min=1000.0f, sum;
	int i=0, j=0;

	while (aArr[i].x <= aX2)
	{
		j = i + 1;
		while (aArr[j].x <= aX2)
		{
			sum = sqrt(pow(aArr[i].x - aArr[j].x, 2.0f) + pow(aArr[i].y - aArr[j].y, 2.0f));
			min = min > sum ? sum : min;
			j++;
			if (aSize <= j) break;
		}
		i++;
		if (aSize <= i) break;
	}
	return min;
}
point makePoint(int aX, int aY)
{
	point tmp;
	tmp.x = aX;
	tmp.y = aY;
	return tmp;
}