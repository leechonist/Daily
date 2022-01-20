#include <iostream>
#include <vector>

using namespace std;
vector<vector<char>> gBoard;

void drawStar(int aX,int aY, int aN)
{
	int temp = aN/3;
	if(aN==1) gBoard[aX][aY]='*';
	else
	{
		drawStar(aX,aY,temp);
		drawStar(aX+temp,aY,temp);
		drawStar(aX+temp*2,aY,temp);
		drawStar(aX,aY+temp,temp);
		drawStar(aX+temp*2,aY+temp,temp);
		drawStar(aX,aY+temp*2,temp);
		drawStar(aX+temp,aY+temp*2,temp);
		drawStar(aX+temp*2,aY+temp*2,temp);
	}
}
int main()
{
	int n,i,j;
	cin>>n;
	gBoard.resize(n);
	
	for(i=0;i<n;i++)
	{
		gBoard[i].assign(n,' ');
	}
	drawStar(0,0,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<gBoard[i][j];
		}
		cout<<endl;
	}
	return 0;
}