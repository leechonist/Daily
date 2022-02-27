#include <stdio.h>
int gRPScode[3] = {32,21,13};
int main()
{
	int player1,player2;
	int re=1,res;
	while(re)
	{
		printf("Rock Papper Scissors!\n");
		puts("1 = rock, 2 = scissors, 3 = paper");
		
		printf("Player1 : ");
		scanf("%d",&player1);
		res = gRPScode[player1-1];
		
		printf("Player2 : ");
		scanf("%d",&player2);
		res += player2*11;
		if(res/10==4) printf("Draw!");
		else if(res%10==4) printf("Player1 win");
		else printf("Player2 win");
		printf("\nre? (0:no 1:yes)  :");
		scanf("%d",&re);
	}
	
	return 0;
}