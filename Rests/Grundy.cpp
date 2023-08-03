const ll mx=16,my=16;
ll dx[]={-2,-2,1,-1};
ll dy[]={1,-1,-2,-2};
ll dp[mx][my];
bool valid(ll x, ll y)
{
    return x>=1 && x<=15 && y>=1 && y<=15;
}
bool losingPos(ll x, ll y)
{
    return (x==1 && y==1) ||
        (x==1 && y==2) ||
        (x==2 && y==1) ||
        (x==2 && y==2);
}
ll grundy(ll x, ll y)
{
    if(losingPos(x,y))
    {
        return 0;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    set<ll> s;
    for(ll i=0; i<4; i++)
    {
        ll xx=x+dx[i];
        ll yy=y+dy[i];
        if(valid(xx,yy))
        {
            s.insert(grundy(xx,yy));
        }
    }
    ll mex=0;
    while(s.count(mex))
    {
        mex++;
    }
    return dp[x][y]=mex;
}
void solve()
{
    ll n; cin>>n;
    ll _xor=0;
    for(ll i=0; i<n; i++)
    {
        ll x,y; cin>>x>>y;
        _xor^=grundy(x,y);
    }
    if(_xor) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
