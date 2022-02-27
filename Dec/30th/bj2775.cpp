//미완
#include <iostream>
#include <vector>
using namespace std;
class AptClass
{
private:
	vector<vector<int>> mArray;
	int mK;
	int mN;
public:
	AptClass()
	{
		vector<int> temp;
		mK=1;
		mN=1;
		mArray.push_back(temp);
		mArray[0].push_back[0];
	}
	int solution(int aK,int aN)
	{
		int i,j;
		for(i=mN;i<=aN;i++) mArray[0].push_back(i);
		for(i=mK;i<=aK;i++)
		{
			vector<int> temp;
			mArray.push_back(temp);
			mArray[i].push_back(0);
			mArray[i].push_back(1);
		}
		for(i=mK;i<aK;i++)
		{
			for(j=mArray[i].size();j<=aN;j++)
			{
				mArray[i].push_back(mArray[i][j-1]+mArray[i-1][j]);
			}
		}
		mN=aN;
		mK=aK;
	}
}

int main()
{
	int T
}