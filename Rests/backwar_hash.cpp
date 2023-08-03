ll b_hash_val[N];
void compute_b_hash(const string& s)
{
    ll n = sz(s);
    b_hash_val[n-1] = s[n-1] - 'a' + 1;
    for (ll i = n-2, j = 1; i >= 0; i--, j++)
    {
        b_hash_val[i] = (b_hash_val[i + 1] + (s[i] - 'a' + 1) * p_pow[j]) % m;
    }
}
ll back_query_hash(ll l, ll r, ll n)
{
    if (r < l)
    {
        return 0;
    }
    if (r == n-1)
    {
        return b_hash_val[l];
    }
    else
    {
        return ((((b_hash_val[l] - b_hash_val[r + 1]) + m) % m) * modIn[n-1-r]) % m;
    }
}