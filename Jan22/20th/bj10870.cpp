#include <iostream>

int fibonach(int aInput)
{
	if(aInput==0) return 0;
	else if(aInput<3) return 1;
	else if(aInput==3) return 2;
	return fibonach(aInput-1)+fibonach(aInput-2);
}
int main()
{
	int n;
	std::cin>>n;
	std::cout<<fibonach(n);
	return 0;
}