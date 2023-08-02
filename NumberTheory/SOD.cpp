//SNOD:
ll SNOD(ll n)
{
   ll sum=0;
   for(ll i=1; i<=n; i++)
   {
      sum+=(n/i);
   }
   return sum;
}

//SOD:
// SOD(12)=1+2+3+4+6+12,
// SOD(12)=(2^0×3^0)+(2^1×3^0)+(2^0×3^1)+(2^2×3^0)+(2^1×3^1)+(2^2×3^1),
// SOD(12)=2^0(3^0+3^1)+2^1(3^0+3^1)+2^2(3^0+3^1),
// SOD(12)=(2^0+2^1+2^2)×(3^0+3^1)
// SOD(N)=(p1^0+p1^1+..+p1^a1)*(p2^0+p2^1+..+p2^a2)*...*(pk^0+pk^1+..+pk^ak)
// p1^0+p1^1+..+p1^a1 = (p1^(a1+1)-1)/(p1-1)
ll modInverse(ll a)
{
    return fastExpo(a, MOD - 2);
}
ll rangeSumModulo(ll a, ll b)
{
    return ((((b - a + 1) % MOD) * ((a + b) % MOD)) % MOD) * modInverse(2) % MOD;
}
void solve()
{
    ll n;
    cin >> n;
    ll sum = 0;
    ll curr = 1;
    while (curr <= n)
    {
        ll divs = n / curr;
        ll next = n / divs + 1;
        sum += (divs % MOD) * (rangeSumModulo(curr, next - 1) % MOD) % MOD;
        sum %= MOD;
        curr = next;
    }
    cout << sum << endl;
}
