#include<iostream>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int,int>> gArr;
void hanoi(int aStart,int aSpot,int aEnd,int aTower)
{
	if(aTower>0){
		hanoi(aStart,aEnd,aSpot,aTower-1);
		gArr.push_back(make_pair(aStart,aEnd));
		hanoi(aSpot,aStart,aEnd,aTower-1);
	}
}
int main()
{
	int n,i,size;
	cin>>n;
	hanoi(1,2,3,n);
	size = gArr.size();
	cout<<size<<'\n';
	for(i=0;i<size;i++)
	{
		cout<<gArr[i].first<<" "<<gArr[i].second<<'\n';
	}
	return 0;
}