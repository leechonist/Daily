#include <iostream>

int main()
{
	int n,i,j;
	std::cin>>n;
	
	for(i=1;i<n;i++) std::cout<<" ";
	std::cout<<"*\n";
	
	for(i=2;i<n;i++)
	{
		for(j=n;j>i;j--) std::cout<<" ";
		std::cout<<"*";
		for(j=0;j<(2*(i-1)-1);j++) std::cout<<" ";
		std::cout<<"*\n";
	}
	if(n>1){
		for(i=0;i<2*n-1;i++) std::cout<<"*";
		std::cout<<"\n";
	}
	return 0;
}