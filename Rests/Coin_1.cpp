//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
const ll N=1000001;
ll dp[N];
ll ara[101];
ll n;
void solve()
{
    ll sum; cin>>n>>sum;
    for(ll i=1; i<=n; i++)
    {
        cin>>ara[i];
        dp[ara[i]]=1;
    }
    for(ll i=1; i<=sum; i++)
    {
        dp[i]=inf;
        for(ll j=1; j<=n; j++)
        {
            if(i-ara[j]>=0)
            {
                dp[i] = min(dp[i],dp[i-ara[j]]+1);
            }
        }
    }
    if(dp[sum]==inf) dp[sum]=-1;
    cout<<dp[sum]<<endl;
}
