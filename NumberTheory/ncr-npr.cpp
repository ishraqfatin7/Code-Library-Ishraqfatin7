void calcFact(ll n)
{
    F[0]=F[1]=1;
    for(ll i=2; i<=n; i++)
    {
        F[i]=(F[i-1]*i)%MOD;
    }
}
ll C(ll n, ll r)
{
    if(r>n) return 0;
    ll ret=F[n];
    ret=(ret*fastExpo(F[r],MOD-2,MOD))%MOD;
    ret=(ret*fastExpo(F[n-r],MOD-2,MOD))%MOD;
    return ret;
}
ll P(ll n, ll r)
{
    if(r>n) return 0;
    ll ret=F[n];
    ret=(ret*fastExpo(F[n-r],MOD-2,MOD))%MOD;
    return ret;
}

