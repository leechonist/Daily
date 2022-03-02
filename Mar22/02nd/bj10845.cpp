#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N,data,i;
    string str;
    queue<int> Q;
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    */
    cin>>N;
    for(i=0;i<N;i++)   
    {
        cin>>str;
        if(str=="push")
        {
            cin>>data;
            Q.push(data);
        }
        else if(str=="pop")
        {
            data = Q.front();
            Q.pop();
            cout<<data<<'\n';
        }
        else if(str=="front")
        {
            if(Q.empty()) cout<<"-1"<<'\n';
            else cout<<Q.front()<<'\n';
        }
        else if(str=="back")
        {
            if(Q.empty()) cout<<"-1"<<'\n';
            else cout<<Q.back()<<'\n';
        }
        else if(str=="size")
        {
            cout<<Q.size()<<'\n';
        }
        else if(str == "empty")
        {
            if(Q.empty()) cout<<1<<'\n';
            else cout<<0<<'\n';
        }
    }

    return 0;
}