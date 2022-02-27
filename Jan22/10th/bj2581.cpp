//15분
#include <iostream>

int* gArr;
void Solution(int,int);
int main()
{
	int M,N;
	std::cin>>M>>N;
	gArr = new int[N+1];
	Solution(M,N);
	return 0;
}

void Solution(int aMin,int aMax)
{
	int i,j,min=0,sum=0;
	for(i=0;i<=aMax;i++)
	{
		gArr[i]=0;
	}
	for(i=2;i<=aMax;i++)
	{
		if(gArr[i]==0 && i > 1)
		{
			for(j=2;(j*i)<=aMax;j++)
				gArr[j*i]=1;
			if(i >= aMin)
			{
				if(min==0) min=i;
				sum+=i;
			}
		}
	}
	if(sum+min == 0) std::cout<<"-1";
	else std::cout<<sum<<std::endl<<min<<std::endl;
}