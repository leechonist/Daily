#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* gArData;
int gSize;

#define UNASSIGNED -1
#define NOISE 0

#define TRUE 1
#define FALSE 0

#define GETX(x) x / 1000;
#define GETY(x) x % 1000;

typedef struct flagSt
{
	int size;
	char* data;
}flagSt;

void flagSum(flagSt* aX,const flagSt* aY);
int getLength(int aX,int aY);
flagSt* SCAN(int aPoint, int aDistance);
int* DBSCAN(int aDistance, int aMin);
int main()
{
	int i;
	int* labels;
	gSize=9;
	gArData=malloc(sizeof(int)*gSize);
	gArData[0] = 10001;		//1,1
	gArData[1] = 20001;		//2,1
	gArData[2] = 10002;		//1,2
	gArData[3] = 100010;	//10,10
	gArData[4] = 110010;	//11,10
	gArData[5] = 100011;	//10,11
	gArData[6] = 1000100;	//100,100
	gArData[7] = 140013;	//14,13
	gArData[8] = 150015;	//15,15
	
	labels = DBSCAN(3,2);
	for(i=0;i<gSize;i++) printf("%d\t",labels[i]);
	free(labels);
	
	return 0;
}
//이웃들의 집합을 합치는 함수
void flagSum(flagSt* aX,const flagSt* aY)
{
	int i;
	for(i=0;i<gSize;i++)
	{
		if(aX->data[i]==FALSE && aY->data[i]==TRUE)
		{
			aX->data[i]=TRUE;
			aX->size++;
		}
	}
}
//점들의 거리를 구하는 함수
int getLength(int aX,int aY)
{
	int x1,x2,y1,y2,width,height,length;
	
	x1=aX/10000;
	x2=aY/10000;
	
	y1=aX%10000;
	y2=aY%10000;
	
	width = x1 > x2 ? x1-x2 : x2-x1;
	height = y1 > y2? y1-y2 : y2-y1;
	length = pow(width,2)+pow(height,2);
	
	return sqrt(length);
	
	
}

flagSt* SCAN(int aPoint, int aDistance)
{
	int i;
	flagSt* flag;
	
	flag = malloc(sizeof(flagSt));
	
	flag->data = malloc(sizeof(char)*gSize);
	flag->size=0;
	
	
	//line 1
	for(i=0;i<gSize;i++)
	{
		
		//line2
		if(getLength(gArData[aPoint],gArData[i]) <= aDistance)
		{
			//line 3
			flag->data[i] = TRUE;
			
			flag->size++;
		//line 4
		}
		else flag->data[i]=FALSE;
		
	//line 5
	}
	//line 6
	return flag;
}

int* DBSCAN(int aDistance, int aMin)
{
	int i,j,k;
	int* labels;
	flagSt* flag1,*flag2;
	
	labels = malloc(sizeof(int)*gSize);
	
	//line 1
	k=0;
	
	//line 2
	for(i=0;i<gSize;i++)
	{
		//line 3
		labels[i] = UNASSIGNED;
	//line 4
	}
	
	//line 5
	for(i=0;i<gSize;i++)
	{
		//line 6
		if(labels[i]==UNASSIGNED)
		{
			//line 7
			flag1 = SCAN(i,aDistance);
			//line8
			if(flag1->size >= aMin)
			{
				//line 9
				k++;
				
				//line 10
				labels[i]=k;
				
				//line 11
				for(j=0;j<gSize;j++)
				{
					//line 12
					if(flag1->data[j] && labels[j]==UNASSIGNED)
					{
						//line 13
						labels[j]=k;
						
						//line 14
						flag2 = SCAN(j,aDistance);
						
						//line 15
						if(flag2->size >= aMin)
						{
							//line 16
							flagSum(flag1,flag2);
							
							free(flag2->data);
							free(flag2);
						//line 17
						}
					//line 18
					}
				//line 19
				}
			//line 20
			}
			//line 21
			else
			{
				//line 22
				labels[i]=NOISE;
			//line 23
			}
			free(flag1->data);
			free(flag1);
		//line 24
		}
	//line 25	
	}
	
	//line 26
	return labels;
}