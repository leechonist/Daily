#include <iostream>
#include <utility>
using namespace std;
pair<int,int> solution(pair<int,int> aFirst,pair<int,int> aSecond,pair<int,int> aThird)
{
	int x,y;
	if(aFirst.first == aSecond.first) x= aThird.first;
	else if(aFirst.first == aThird.first) x = aSecond.first;
	else x = aFirst.first;
	
	if(aFirst.second == aSecond.second) y = aThird.second;
	else if(aFirst.second == aThird.second) y = aSecond.second;
	else y = aFirst.second;
	
	return make_pair(x,y);
}
int main()
{
	pair<int,int>first,second,third,fourth;
	int x,y;
	cin>>x>>y;
	
	first = make_pair(x,y);
	cin>>x>>y;
	second = make_pair(x,y);
	cin>>x>>y;
	third = make_pair(x,y);
	
	fourth = solution(first,second,third);
	cout<<fourth.first<<" "<<fourth.second<<endl;
	
	return 0;
}