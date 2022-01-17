#include <vector>
#include <iostream>
using namespace std;
void setPrime(vector<int>& aPrime,int aCount)
{
	int i,j,c = 1;
	for(i=2;i<aCount;i++)
	{
		if(aPrime[i]==0)
		{
			aPrime[i] = c;
			c++;
		}
		for(j=i+i;j<aCount;j+=i)
		{
			aPrime[j] = -1;
		}
	}
}
void solution()
{
	vector<int> arr;
	vector<int> prime;
	int temp,min,max=0,i;
	do
	{
		cin>>temp;
		max = max>temp?max:temp;
		arr.push_back(temp);
	}while(temp>0);
	prime.assign((2*max)+1,0);
	setPrime(prime,(2*max)+1);
	for(i=0;i<(arr.size()-1);i++)
	{
		temp = arr[i];
		while(prime[temp] < 0)
		{
			temp--;
		}
		min = prime[temp];
		temp = arr[i]*2;
		while(prime[temp] < 0)
		{
			temp--;
		}
		max = prime[temp];
		cout<<max-min<<endl;
	}
	/*
	for(i=0;i<prime.size();i++)
	{
		std::cout<<prime[i]<<"\t";
		if(i%9==0) cout<<endl;
	}
	*/
}
int main()
{
	solution();
	return 0;
}