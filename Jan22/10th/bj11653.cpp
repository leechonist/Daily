//18분
#include <iostream>
void Solution(int);
int isPrime(int);
int main()
{
	int N;
	std::cin>>N;
	if(N==1) return 0;
	Solution(N);
	return 0;
}
int isPrime(int Input)
{
	int i=2;
	while(i*i <= Input)
	{
		if(Input%i == 0) return -1;
		i++;
	}
	return 1;
}
void Solution(int Input)
{
	int i;
	while(isPrime(Input) == -1)
	{
		for(i=2;i<=Input/2;i++)
		{
			if(Input%i == 0 && isPrime(i) == 1)
			{
				std::cout<<i<<std::endl;
				Input/=i;
				i=Input;
			}
		}
	}
	std::cout<<Input<<std::endl;
}