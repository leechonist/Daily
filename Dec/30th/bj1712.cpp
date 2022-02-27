#include <iostream>
int solution(int aA,int aB,int aC)
{
	int benefit=aC-aB;
	if(benefit <= 0) return -1;
	return aA/benefit+1;
}

int main()
{
	int A,B,C;
	std::cin>>A>>B>>C;
	std::cout<<solution(A,B,C)<<std::endl;
	return 0;
}