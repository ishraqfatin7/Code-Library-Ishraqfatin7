double dp[105][10005];
bool vis[105][10005];
double func(int pos,int m,double money[],double prob[])
{
    if(m<0)return 0.0;
    if(pos==n+1)return(m==0?1.0:0.0);
    if(vis[pos][m])return dp[pos][m];
    vis[pos][m]=true;
    return dp[pos][m]=max(func(pos+1,m,money,prob),func(pos+1,m-money[pos],money,prob)*(1-prob[pos]));
}
