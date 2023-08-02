ll mod_expo(ll x, ll y, ll m)
{
    if(y==0)return 1;
    ll ans=mod_expo(x,y/2,m);
    ans*=ans;
    ans%=m;
    if(y%2==0)return ans%m;
    else return ans*x%m;
}
int main()
{
    ll n;
    cin>>n;
    ll a[n],m[n],M,M1[n],x,M1_inv[n];
    M=1;
    for(ll i=0; i<n; i++)
    {
        cin>>m[i]>>a[i];
        M*=m[i];
    }
    for(ll i=0; i<n; i++)
    {
        M1[i]=M/m[i];
        ll y=M1[i]*a[i]%M,z=0;
        for(ll j=1;; j++)
        {
            ll ans=M1[i]*j%m[i];
            z=(z+y)%M;phi
            if(ans==1)
            {
                M1[i]=z;
                break;
            }
        }
    }
    x=0;
    for(ll i=0; i<n; i++)
    {
        x=(x+M1[i])%M;
    }
    cout<<x;
    return 0;
}
