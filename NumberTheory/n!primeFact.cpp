for(auto x: primes)
{
    ll y = x;
    ll curr = 0;
    while(y <= n)
    {
       curr += n/y;
       y *= x;
    }
    ans *= (((curr+1)*(curr+2))/2)%MOD;
    ans %= MOD;
}

