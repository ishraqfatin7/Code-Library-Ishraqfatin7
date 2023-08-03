ll dp[11][2][92];
int a,b;
ll func(int pos, bool isSmall, int digitSum, string &str)
{
    if(pos>=10)return digitSum==x;
    if(dp[pos][isSmall][digitSum]!=-1)return dp[pos][isSmall][digitSum];
    int lo=0,hi=str[pos]-'0';
    ll re=0;
    if(isSmall)hi=9;
    for(int idx=lo; idx<=hi; idx++)
    {
        ll val=func(pos+1,isSmall|(idx<hi), digitSum+idx,str);
        re+=val;
    }
    return dp[pos][isSmall][digitSum]=re;
}
int main()
{
    iamspeed
    string str,str2;

    cin>>a>>b>>x;
    str2=to_string(b);
    while(str2.size()<10)str2='0'+str2;
    str=to_string(a-1);
    while(str.size()<10)str='0'+str;
    memset(dp,-1,sizeof(dp));
    ans=func(0,0,0,str2);
    memset(dp,-1,sizeof(dp));
    sum=func(0,0,0,str);
    cout<<ans-sum<<endl;
    return 0;
}
