#include <iostream>

int solution(int aA,int aB,int aV)
{
	int day=1,temp=aA-aB;
	aV -= aA;
	if(aV > 0) day += ((aV%temp)>0?aV/temp+1:aV/temp);
	return day;
}
int main()
{
	int A,B,V;
	std::cin>>A>>B>>V;
	std::cout<<solution(A,B,V)<<std::endl;
	return 0;
}