int MatrixChainOrder(int p[],int i, int j)
{
    if(i==j)return dp[i][j]=0;
    if(dp[i][j]!=-1)return dp[i][j];
    int k,mn=INT_MAX,cnt;
    for(int k=i; k<j; k++)
    {
        dp[i][k]=MatrixChainOrder(p,i,k);
        dp[k+1][j]=MatrixChainOrder(p,k+1,j);
        cnt=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
        if(cnt<mn)
        {
            mn=cnt;
            bracket[i][j]=k;
        }
    }
    return dp[i][j]=mn;
}