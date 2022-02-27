#include <iostream>
#include <utility>
#include <vector>

using namespace std;
void solution()
{
    int j,n,kg,cm,i,rank;
    vector<pair<int,int>> arInfo1;
    vector<int> arRank1;
    
    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>kg>>cm;
        arInfo1.push_back(make_pair(kg,cm));
    }
    for(i=0;i<n;i++)
    {
        rank=1;
        for(j=0;j<n;j++)
        {
            if(i==j) continue;
            if(arInfo1[i].first <arInfo1[j].first &&
            arInfo1[i].second <arInfo1[j].second) rank++; 
        }
        arRank1.push_back(rank);
    }
    for(i=0;i<n;i++)
        cout<<arRank1[i]<<" ";
    cout<<endl;
    
}
int main()
{
    solution();
    return 0;
}