#include <iostream>
#include <string>
void print(short aNumber, short aCount,short aMax, short aMaxNum,std::string aStr)
{
    int i;
    aStr = aStr + std::to_string(aNumber) + ' ';
    if(aCount==aMax){
        std::cout<<aStr<<"\n";
        return;
    }
    for(i=0;i<aMaxNum;i++)
    {
        print(i+1,aCount+1,aMax,aMaxNum,aStr);
    }
}
void solution()
{
    short N,M,i,j;
    std::string str="";
    std::cin>>N>>M;
    for(i=0;i<N;i++)
    {
        print(i+1,1,M,N,str);
    }
}
int main()
{
    solution();
    return 0;
}