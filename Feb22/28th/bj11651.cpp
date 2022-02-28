#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool check(const pair<int,int>& aX,const pair<int,int>& aY)
{
    if(aX.second!=aY.second) return aX.second<aY.second;
    return aX.first<aY.first;
}
void solution()
{
    int i,N,x,y;
    vector<pair<int,int>> arData;

    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>x>>y;
        arData.push_back(make_pair(x,y));
    }
    sort(arData.begin(),arData.end(),check);
    for(i=0;i<N;i++)
    {
        cout<<arData[i].first<<" "<<arData[i].second<<"\n";
    }
}
int main()
{
    solution();
    return 0;
}