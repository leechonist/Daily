#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
int get_value(const std::vector<int>& aArData,const int& aN)
{
    int i,j=-1,cur=4000,max=0,count=0,res;
    std::pair<int,int>* arCount = new std::pair<int,int>[aN];
    for(i=0;i<aN;i++)
    {
        if(aArData[i]!=cur)
        {
            cur = aArData[i];
            j++;
            arCount[j] = std::make_pair(cur,0);
            if(j>0)
                max = max > arCount[j-1].second? max : arCount[j-1].second;
        }
        arCount[j].second++;
    }
    if(max==0) return cur;
    max = max > arCount[j].second? max : arCount[j].second;
    for(i=0;i<=j && count < 2;i++)
    {
        if(arCount[i].second == max)
        {
            count++;
            res = arCount[i].first;
        }
    }
    delete arCount;
    return res;
}
void solution()
{
    int sum=0,min,max,N,mid,i,data,average;
    std::vector<int> arData;

    std::cin>>N;
    arData.resize(N);
    for(i=0;i<N;i++)
    {
        std::cin>>data;
        if(i==0) max = min = data;
        else{
            if(min>data) min = data;
            if(max<data) max = data;
        }
        arData[i]=data;
        sum += data;
    }
    average = sum/N;
    data = sum%N;
    if(data>0 && N <= data*2) average++;
    if(data<0 && N <= data*(-2)) average --;
    std::cout<<average<<std::endl;
    
    std::sort(arData.begin(),arData.end());
    std::cout<<arData[N/2]<<std::endl;

    std::cout<<get_value(arData,N)<<std::endl;

    std::cout<<max-min<<std::endl;


}
int main()
{
    solution();
    return 0;
}