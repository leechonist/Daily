#include <iostream>
#include <utility>
#include <queue>

using namespace std;
void solution()
{
    int i,j,data,x,y,count,temp,position;
    int arSudoku[9][9];
    /* = {{0,3,5,4,6,9,2,7,8},{7,8,2,1,0,5,6,0,9},{0,6,0,2,7,8,1,3,5},
    {3,2,1,0,4,6,8,9,7},{8,0,4,9,1,3,5,0,6},{5,9,6,8,2,0,4,1,3},
    {9,1,7,6,5,2,0,8,0},{6,0,3,7,0,1,9,5,2},{2,5,8,3,9,4,7,6,0}};
    */
    bool arFlag[3][9][9]={true,};
    //0 = 행 1 = 열 2 = 사각
    queue<pair<int,int>> qZero;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            arFlag[0][i][j]=true;
            arFlag[1][i][j]=true;
            arFlag[2][i][j]=true;
        }
    }

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>data;
            //data = arSudoku[i][j];
            if(data==0) qZero.push(make_pair(i,j));
            else
            {
                arFlag[0][i][data-1] = false;
                arFlag[1][j][data-1] = false;
                arFlag[2][(i/3)*3+j/3][data-1] = false;
            }
            arSudoku[i][j] = data;
        }
    }

    while(!qZero.empty())
    {
        x=qZero.front().first;
        y=qZero.front().second;
        qZero.pop();

        data = (x/3)*3+y/3;
        count=0;
        for(i=0;i<9;i++)
        {
            if(arFlag[0][x][i]&&arFlag[1][y][i]&&arFlag[2][data][i])
            {
                temp=i+1;
                count+=1;
            }
        }
        if(count==1)
        {        
            arSudoku[x][y]=temp;
            arFlag[1][y][temp-1]=arFlag[2][data][temp-1]=arFlag[0][x][temp-1]=false;
        }
        else 
        {
            qZero.push(make_pair(x,y));
        }
    }
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++) cout<<arSudoku[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    solution();
    return 0;
}