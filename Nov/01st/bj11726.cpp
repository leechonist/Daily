//2*n 개의 사각형
//문제점 : long long도 부족했음 계산을 하면서 %1007을 해줬음
#include <iostream>
unsigned long long sol(int aN,int aCur)
{
	if(aCur==1) return 1;
	if(aCur==2) return 2;
	return sol(aN,aCur-1)+sol(aN,aCur-2);
}
int main()
{
	int n,cur=0;
	unsigned long long res;
	std::cin>>n;
	res = sol(n,n);
	std::cout<<res%10007;
	return 0;
}

/*
1	2	3	4
1  2    3   5
	*/