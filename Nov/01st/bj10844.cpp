//망함 다시하기
#include <iostream>

int main()
{
	unsigned long long* arr;
	int i,n;
	std::cin>>n;
	arr = new unsigned long long[n+1];
	arr[0]=0;
	arr[1]=9;
	for(i=2;i<=n;i++)
	{
		arr[i]=((i*8)-1)%1000000;
	}
	std::cout<<arr[n]<<std::endl;
	return 0;
}