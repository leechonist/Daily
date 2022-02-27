#include <iostream>
#include <cmath>
using namespace std;
void solution(int aInput)
{
	cout<<fixed;
	std::cout.precision(6);
	std::cout<<M_PI*aInput*aInput<<std::endl;
	std::cout<<2.0*aInput*aInput<<std::endl;
}
int main()
{
	int n;
	std::cin>>n;
	solution(n);
	return 0;
}