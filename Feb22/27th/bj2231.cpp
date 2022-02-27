#include <iostream>
int solution(int input);
int get_value(int input);
int main()
{
    int n;
    std::cin>>n;
    std::cout<<solution(n)<<std::endl;
    return 0;
}
int get_value(int input)
{
    
    int temp = input,res = input;
    while(temp > 0)
    {
        res += temp%10;
        temp /= 10;
        //std::cout<<temp<<std::endl;
    }
    return res;
}

int solution(int input)
{
    int i=0,temp1=input-1,temp2,res = 0;
    if(input <10 && input%2 == 0) return input/2;
    else if(input<10) return res;

    while(temp1 > input/10)
    {
        temp2 = get_value(temp1);
        if(input == temp2)
        {
            res = temp1;
        }
        temp1--;
    }
    return res;

}