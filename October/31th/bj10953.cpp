#include <iostream>
#include <string>
int get_result(std::string& aStr)
{
	int A=0,B=0,i=0,res;
	while(aStr.at(i)!=',')
	{
		A *= 10;
		A += (aStr.at(i)-'0');
		i++;
	}
	i++;
	for(;i<aStr.size();i++)
	{
		B*=10;
		B+=(aStr.at(i)-'0');
	}
	res = A+B;
	return res;
}
int main()
{
	std::string str;
	int T,i,res;
	std::cin>>T;
	for(i=0;i<T;i++)
	{
		std::cin>>str;
		std::cout<<get_result(str)<<std::endl;
	}
	return 0;
}