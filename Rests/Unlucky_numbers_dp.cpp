bool dp[20][10][10][2][2];
void ye(string str, int idx, int mxd, int mnd, bool f, bool ff)
{
    if(idx>=ss.size())
    {
        if(mn>mxd-mnd)
        {
            mn=mxd-mnd;
            ans_str=str;
        }
        return;
    }
    bool &val=dp[idx][mxd][mnd][f][ff];
    if(val)return;
    val=true;
    if(f&&ff)
    {
        for(int ind=0; ind<10; ind++)
        {
            str[idx]=ind+'0';
            ye(str,idx+1,max(mxd,ind),min(mnd,ind),f,ff);
        }
    }
    else if(f)
    {
        for(int ind=s[idx]-'0'; ind<=9; ind++)
        {
            str[idx]=ind+'0';
            ye(str,idx+1,max(mxd,ind),min(mnd,ind),f,ind>(s[idx]-'0'));
        }
    }
    else if(ff)
    {
        for(int ind=0; ind<=ss[idx]-'0'; ind++)
        {
            str[idx]=ind+'0';
            ye(str,idx+1,max(mxd,ind),min(mnd,ind),ind<(ss[idx]-'0'),ff);
        }
    }
    else
    {
        for(int ind=s[idx]-'0'; ind<=ss[idx]-'0'; ind++)
        {
            str[idx]=ind+'0';
            ye(str,idx+1,max(mxd,ind),min(mnd,ind),ind<(ss[idx]-'0'),ind>(s[idx]-'0'));
        }
    }
}
