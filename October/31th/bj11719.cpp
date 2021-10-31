#include <iostream>
#include <string>
#define _GOORM_
int main()
{
	char str[10000];
	#ifdef _BJ_
	std::cin.getline(str,10000,EOF);
	#endif
	#ifdef _GOORM_
	std::cin.getline(str,10000,'.');
	#endif
	std::cout<<str;
	return 0;
}