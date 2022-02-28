#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sortFirst(const pair<int,int>& aX,const pair<int,int>& aY)
{
    return aX.first < aY.first;
}
bool sortSecond(const pair<int,int>& aX,const pair<int,int>& aY)
{
    return aX.second < aY.second;
}
void solution()
{
    int N,i,data,temp=0,j=0;
    vector<pair<int,int>> arSorted;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>data;
        arSorted.push_back(make_pair(data,i));
    }
    sort(arSorted.begin(),arSorted.end(),sortFirst);
    for(i=0;i<N;)
    {
        temp = arSorted[i].first;
        while( i<N &&temp==arSorted[i].first)
        {
            arSorted[i].first=j;
            i++;
        }
        j++;
    }
    sort(arSorted.begin(),arSorted.end(),sortSecond);
    for(i=0;i<N;i++)
    {
        cout<<arSorted[i].first<<" ";
    }
}
int main()
{
    solution();
    return 0;
}