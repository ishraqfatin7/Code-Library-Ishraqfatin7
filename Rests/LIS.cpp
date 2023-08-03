const ll N=10005;
ll ara[N];
ll dp[N]; // dp[i] = maximum length of LIS when the last element of LIS is ith element
ll n;
ll F(ll i, ll j) // ll i = current index, j = previous index
{
    if(i>n)
        return 0;
    if(dp[j]!=-1)
        return dp[j];
    ll maxx=0;
    if(ara[i]>ara[j])
    {
        maxx=max(maxx,F(i+1,i)+1);
    }
    maxx=max(maxx,F(i+1,j));
    return dp[j]=maxx;
}
