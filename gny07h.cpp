// 2008-08-19
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 21
using namespace std;
int dp[MAXSIZE][2][2][2][2];
int main()
{
	int T,i,N;
	dp[1][0][0][0][0]=1;
	dp[1][0][0][1][1]=1;
	dp[1][0][1][1][0]=1;
	dp[1][1][1][0][0]=1;
	dp[1][1][1][1][1]=1;
	for (i=2; i<=MAXSIZE; i++)
	{
		dp[i][0][0][0][0]=dp[i-1][1][1][1][1];
		dp[i][0][0][1][1]=dp[i-1][1][1][0][0]+dp[i-1][1][1][1][1];
		dp[i][0][1][1][0]=dp[i-1][1][0][0][1]+dp[i-1][1][1][1][1];
		dp[i][1][1][0][0]=dp[i-1][0][0][1][1]+dp[i-1][1][1][1][1];
		dp[i][0][1][0][1]=dp[i-1][1][0][1][0];
		dp[i][1][0][1][0]=dp[i-1][0][1][0][1];
		dp[i][1][0][0][1]=dp[i-1][0][1][1][0];
		dp[i][1][1][1][1]=dp[i-1][1][1][1][1]+dp[i-1][1][1][0][0]+dp[i-1][0][0][1][1]+dp[i-1][0][1][1][0]+dp[i-1][0][0][0][0];
	}
	scanf("%d",&T);
	for (i=1; i<=T; i++)
	{
		scanf("%d",&N);
		printf("%d %d\n",i,dp[N][1][1][1][1]);
	}
	return 0;
}
