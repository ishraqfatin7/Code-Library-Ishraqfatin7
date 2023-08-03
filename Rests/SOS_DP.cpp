bool vis[N][33];
int freq[N],dp[N][33];
int countBit(int x)
{
    int cnt=1;
    while(x) cnt++, x/=2;
    return cnt;
}
bool isSet(int mask, int curBit)
{
    return (bool)(mask&(1<<curBit));
}
int changeBit(int mask,int curBit)
{
    return (mask^(1<<curBit));
}
int func(int mask, int curBit)
{
    if(curBit==-1)return (freq[mask]==0?-1:mask);
    if(vis[mask][curBit])return dp[mask][curBit];
    vis[mask][curBit]=true;
    int fir=func(mask,curBit-1);
    if(isSet(mask,curBit))
    {
        int sec=func(changeBit(mask,curBit),curBit-1);
        return dp[mask][curBit]=max(fir,sec);
    }
    return dp[mask][curBit]=fir;
}
int main()
{
    cin>>n; int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    for(int i=0; i<n; i++)
    {
        int revNum=((1<<countBit(a[i]))-1)^(a[i]);
        int submask=func(revNum,countBit(a[i]));
        cout<<a[i]<<' '<<submask<<endl;
    }
}