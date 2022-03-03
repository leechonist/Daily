#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solution()
{
    int K,N,data,i,j,max=0;
    vector<int> arData;
    vector<int> arCut;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>K>>N;
    for(i=0;i<K;i++)
    {
        std::cin>>data;
        arData.push_back(data);
        arCut.push_back(1);
    }

    for(i=K;i<N;i++)
    {
        max=0;
        for(j=1;j<K;j++)
        {
            max = arData[max]/(arCut[max]+1) > arData[j]/(arCut[j]+1) ? max : j;
        }
        arCut[max]++;
    }

    max = arData[0]/arCut[0];
    for(i=1;i<K;i++)
    {
        data = arData[i]/arCut[i];
        max = max > data?data:max;
    }

    cout<<max;
}
int main()
{
    solution();
    return 0;
}