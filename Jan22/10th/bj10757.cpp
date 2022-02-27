//13분
#include <string>
#include <iostream>
using namespace std;
string Solution();
int main()
{
	cout<<Solution();
	return 0;
}
string Solution()
{
	int len1,len2,temp,carry=0;
	string num1,num2,res;
	cin>>num1>>num2;
	len1 = num1.size();
	len2 = num2.size();
	while(len1+len2 > 0)
	{
		temp = carry;
		if(len1 > 0){
			temp += num1.at(len1-1)-'0';
			len1--;
		}
		if(len2 > 0){
			temp += num2.at(len2-1)-'0';
			len2--;
		}
		if(temp>=10)
		{
			carry=1;
			temp %= 10;
		}
		else
		{
			carry = 0;
		}
		res = (char)(temp+'0')+res ;
	}
	if(carry>0) res = '1'+res ;
	return res;
}