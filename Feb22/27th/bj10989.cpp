#include <iostream>
using namespace std;
int main()
{
    long long N,i;
    short data,max,j;
    long long* arData = new long long[10001];
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(i=0;i<10001;i++) arData[i]=0;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>data;
        arData[data]++;
        max = max>data?max:data;
    }
    for(j=0;j<=max;j++)
    {
        N=arData[j];
        while(N>0)
        {
            cout<<j<<'\n';
            N--;
        }
    }
    return 0;
}