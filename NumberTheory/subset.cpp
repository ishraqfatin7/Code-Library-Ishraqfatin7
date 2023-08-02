#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << __builtin_parity(15) << '\n';
    cout << __builtin_parity(31) << '\n';
    int l, r, k;
    cin >> l >> r >> k;
    vector<int> prime(k);
    /// prime = {2, 3, 5} --> k = 3
    for (int &x : prime)
        cin >> x;
    int ans = 0;
    for (int mask = 1; mask < 1 << k; ++mask)
    {
        int prod = 1;
        for (int i = 0; i < k; ++i)
        {
            if (mask & 1 << i)
                prod *= prime[i];
        }
        int here = r / prod - (l - 1) / prod;
        if (__builtin_parity(mask))
            ans += here;
        else
            ans -= here;
    }
    cout << ans << '\n';
    return 0;
}
