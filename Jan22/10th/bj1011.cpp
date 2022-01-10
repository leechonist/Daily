//1시 1분
#include <iostream>
using namespace std;
int Solution(int,int);
int main()
{
	int T,i,x,y;
	int* Arr;
	cin>>T;
	Arr = new int[T];
	for(i=0;i<T;i++)
	{
		cin>>x>>y;
		Arr[i]=Solution(x,y);
	}
	for(i=0;i<T;i++)
	{
		cout<<Arr[i]<<endl;
	}
	delete Arr;
	
	return 0;
}
int Solution(int aX,int aY)
{
	int count=0,len=1;
	while(aX<aY)
	{
		if(aY-aX < len)
		{
			return count+1;
		}
		if(aX+len <= aY)
		{
			count++;
			aX += len;
		}
		if(aY-len >= aX)
		{
			count++;
			aY -= len;
		}
		len++;
	}
	return count;
}