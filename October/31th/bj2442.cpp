#include <iostream>

int main()
{
	int n,i,j;
	std::cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=i;j<(n-1);j++)
			std::cout<<" ";
		for(j=0;j<(2*(i+1)-1);j++)
			std::cout<<"*";
		std::cout<<std::endl;
	}
	return 0;
}