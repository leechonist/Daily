#include <iostream>
int main()
{
	int i,j,n;
	std::cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			std::cout<<'*';
		}
		for(j=0;j<(n-i)*2;j++)
		{
			std::cout<<' ';
		}
		for(j=0;j<i;j++)
		{
			std::cout<<'*';
		}
		std::cout<<std::endl;		
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=0;j<i;j++)
		{
			std::cout<<'*';
		}
		for(j=0;j<(n-i)*2;j++)
		{
			std::cout<<' ';
		}
		for(j=0;j<i;j++)
		{
			std::cout<<'*';
		}
		std::cout<<std::endl;		
	}
	return 0;
}