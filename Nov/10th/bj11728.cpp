#include <iostream>
int main()
{
    int* A,*B,*res;
    int m,n,i,j,k;
    std::cin>>m>>n;
    A = new int[m];
    B = new int[n];
    res = new int[m+n];
    for(i=0;i<m;i++)
    {
        std::cin>>k;
        A[i]=k;
    }
    for(j=0;j<n;j++)
    {
        std::cin>>k;
        B[i]=k;
    }
    i=j=k=0;
    while((i<m)||(j<n))
    {
        printf("%d",k);
        if(i>=m)
        {
            res[k]=B[j];
            j++; k++;
        }
        else if(j>=n)
        {
            res[k]=A[i];
            i++; k++;
        }
        else if(A[i]<B[j])
        {
            res[k]=A[i];
            i++; k++;
        }
        else if(B[j] < A[i])
        {
            res[k]=B[j];
            j++; k++;
        }
    }
    for(i=0;i<m+n;i++)
    {
        std::cout<<res[i]<<" ";
    }
    delete A;
    delete B;
    delete res;
    return 0;
}