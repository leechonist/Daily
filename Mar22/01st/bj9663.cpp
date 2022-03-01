#include <iostream>
#include <vector>
bool CanPlace(const std::vector<int>& aArData, const int& aData)
{
    int i,size = aArData.size(),j;

    for(i=0;i<size;i++)
    {
        if(aArData[i]==aData) return false;
        if(abs(i-size) == abs(aArData[i]-aData)) return false;
    }
    return true;
}
int check(std::vector<int> aArData,const int& aInput,int aData)
{
    int i,sum=0;

    aArData.push_back(aData);
    if(aArData.size()==aInput) return 1;
        
    for(i=0;i<aInput;i++){
        if(CanPlace(aArData,i))
            sum+=check(aArData,aInput,i);
    }
    return sum;
}
int solution(const int& aInput)
{
    int i,j,sum=0;
    std::vector<int> arData;
    for(i=0;i<aInput;i++)
    {
        sum+= check(arData,aInput,i);
    }
    return sum;
}
int main()
{
    int N;
    std::cin>>N;
    std::cout<<solution(N);

    return 0;
}