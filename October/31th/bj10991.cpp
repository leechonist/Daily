#include <iostream>

int main()
{
	int n,i,j;
	std::cin>>n;
	for(i=1;i<n;i++)
	{
		for(j=(n-1);j>i;j--)
		{
			std::cout<<" ";
		}
		for(j=0;j<i;j++)
		{
			std::cout<<" *";
		}
		std::cout<<std::endl;
	}
	for(i=0;i<n;i++)
	{
		std::cout<<"*";
		if(i<(n-1)) std::cout<<" ";
		else std::cout<<"\n";
	}
	return 0;
}