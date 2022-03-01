#include <iostream>
#include <vector>
#include <string>
void print(short aNumber, short aCount,short aMax, short aMaxNum,std::vector<bool> aArFlag,std::string aStr)
{
    int i;
    if(aArFlag[aNumber-1]) return;
    aArFlag[aNumber-1] = true;
    aStr = aStr + std::to_string(aNumber) + ' ';
    if(aCount==aMax){
        std::cout<<aStr<<"\n";
        return;
    }
    for(i=0;i<aMaxNum;i++)
    {
        print(i+1,aCount+1,aMax,aMaxNum,aArFlag,aStr);
    }
}
void solution()
{
    short N,M,i,j;
    std::string str="";
    std::vector<bool> arFlag;
    std::cin>>N>>M;
    arFlag.assign(N,false);
    for(i=0;i<N;i++)
    {
        print(i+1,1,M,N,arFlag,str);
    }
}
int main()
{
    solution();
    return 0;
}