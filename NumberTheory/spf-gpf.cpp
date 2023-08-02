#include <bits/stdc++.h>
using namespace std; // for
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
using ll = long long;
const int N = 1e6 + 9;
ll lpf, gpf = 0, dpf = 0, npf = 0, ndiv = 1, sdiv = 1;
ll spf[N];
ll arr[N];
int mark[N];
void sieve()
{

    for (ll i = 2; i * i <= N; i++)
    {
        if (!mark[i])
        {
            spf[i] = i;
            for (ll j = i * 2; j <= N; j += i)
            {
                mark[j] = 1;
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    }
    for (ll i = 2; i <= N; i++)
        if (spf[i] == 0)
            spf[i] = i;
}
ll fastExpo(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

int main()
{
    FAST;
    sieve();
    int n;
    cin >> n; // read
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        ll x = arr[i];
        lpf = spf[x], dpf = 0, gpf = 0, npf = 0, ndiv = 1, sdiv = 1;
        while (x > 1)
        {
            gpf = max(gpf, spf[x]);
            ll d = spf[x];
            ll count = 0;
            while (!(x % d))
            {
                x /= d;
                count++;
                npf++;
            }
            ndiv *= (count + 1);
            sdiv *= (fastExpo(d, count + 1) - 1) / (d - 1);
            dpf++;
        }
        printf("%lld %lld %lld %lld %lld %lld\n", lpf, gpf, dpf, npf, ndiv, sdiv);
    }
}