#include <iostream>

int main()
{
	int n,i,j;
	std::cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<n;j++)
			std::cout<<" ";
		for(j=i;j>0;j--)
			std::cout<<"*";
		std::cout<<std::endl;
	}
	for(i=n-1;i>0;i--)
	{
		for(j=i;j<n;j++)
			std::cout<<" ";
		for(j=i;j>0;j--)
			std::cout<<"*";
		std::cout<<std::endl;
	}
	return 0;
}