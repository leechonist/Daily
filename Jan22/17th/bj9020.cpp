#include <iostream>
#include <vector>

using namespace std;
void setPrime(vector<int>& aPrime,int aMax)
{
	int i,j,temp=2;
	aPrime.assign(aMax+1,1);
	for(i=2;i<=aMax;i++)
	{
		if(aPrime[i]==1)
		{
			for(j=i+i;j<=aMax;j+=i)
			{
				aPrime[j]=0;
			}
			aPrime[i] = i;
			temp = i;
		}
		else
		{
			aPrime[i]=temp;
		}
	}
}
void solution()
{
	vector<int> prime,arr;
	int input,i,T,max=0,temp,p1,p2;
	cin>>T;
	for(i=0;i<T;i++)
	{
		cin>>input;
		max = max > input ? max : input;
		arr.push_back(input);
	}
	setPrime(prime,max);
	for(i=0;i<T;i++)
	{
		temp = arr[i];
		p1 = temp/2;
		while(1)
		{
			p1 = prime[p1];
			
			p2 = temp - p1;
			if(prime[p2]==p2)
			{
				cout<<p1<<" "<<p2<<"\n";
				break;
			}
			else
			{
				p1--;
			}
		}
	}
	
}
int main()
{
	solution();
	return 0;
}