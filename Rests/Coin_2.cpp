//Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ways you can produce a money sum x using the available coins.
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
    }
    dp[0]=1;
    for(ll i=1; i<=sum; i++)
    {
        dp[i]=0;
        for(ll j=1; j<=n; j++)
        {
            if(i-ara[j]>=0)
            {
                dp[i]+=dp[i-ara[j]];
                dp[i]%=MOD;
            }
        }
    }
    cout<<dp[sum]<<endl;
}
