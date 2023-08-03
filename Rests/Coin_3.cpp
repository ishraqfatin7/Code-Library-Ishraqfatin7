//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
void solve()
{
    int n,sum; cin>>n>>sum;
    vector<int> ara(n+1);
    for(ll i=1; i<=n; i++)
    {
        cin>>ara[i];
    }
    int dp[n+1][sum+1];
    memo(dp,0);
    dp[0][0]=1;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=0; j<=sum; j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j-ara[i]>=0)
            {
                dp[i][j]+=dp[i][j-ara[i]];
                dp[i][j]%=MOD;
            }
        }
    }
    cout<<dp[n][sum]<<endl;
}
