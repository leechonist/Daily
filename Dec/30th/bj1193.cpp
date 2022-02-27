#include <iostream>
void solution(int aX)
{
	int temp1=1,temp2=1,temp3=1,i,count=1;
	for(i=1;(temp1+i) <= aX;i++)
	{
		count++;
		temp1+=i;
		temp3++;
	}
	for(i=0;i<(aX-temp1);i++)
	{
		temp2++;
		temp3--;
	}
	if(count%2==1) std::cout<<temp3<<"/"<<temp2<<std::endl;
	else std::cout<<temp2<<"/"<<temp3<<std::endl;
}
int main()
{
	int X;
	std::cin>>X;
	solution(X);
	return 0;
}


/*
1	2	4	7	11	16
3	5	8	12	17
6	9	13	18
10	14	19
15	20
21
*/