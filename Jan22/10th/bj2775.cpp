//34분

#include <vector>
#include <iostream>
#include <utility>
using namespace std;
class ApartClass
{
private:
	vector<vector<int>> mApt;
public:
	ApartClass()
	{
	}
	void setApt(int aFloor,int aRoom)
	{
		int i,j;
		vector<int> temp;
		mApt.push_back(temp);
		for(i=0;i<=aRoom;i++)
		{
			mApt[0].push_back(i);
		}
		for(i=1;i<=aFloor;i++)
		{
			mApt.push_back(temp);
			mApt[i].push_back(0);
			for(j=1;j<=aRoom;j++)
			{
				mApt[i].push_back(mApt[i][j-1]+mApt[i-1][j]);
			}
		}
	}
	vector<int>& operator[](int x)
	{
		return mApt[x];
	}
};
void Solution()
{
	vector<pair<int,int>> data;
	ApartClass Apt;
	int T,k,n,i,maxFloor=0,maxRoom=0;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>k>>n;
		data.push_back(make_pair(k,n));
		maxRoom=maxRoom>n?maxRoom:n;
		maxFloor=maxFloor>k?maxFloor:k;
	}
	Apt.setApt(maxFloor,maxRoom);
	for(i=0;i<T;i++)
	{
		cout<<Apt[data[i].first][data[i].second]<<endl;
	}
}
int main()
{
	Solution();
	return 0;
}