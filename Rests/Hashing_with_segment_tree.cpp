
#define ll long long 
const int N = 2e5 + 9;
ll modInverse(ll a, ll m) // calculates inverse modulo
{
    ll m0 = m;
    ll y = 0, x = 1;
    if (m == 1)
    {
        return 0;
    }
    while (a > 1)
    {
        ll q = a / m;
        ll t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
    {
        x += m0;
    }
    return x;
}
ll p_pow[N]; // p_pow[i] = p^i % m
ll modIn[N]; // inverse modulo for p_pow[]
ll hash_val[2][N]; // prefix sum of hash values
const ll p = 31; // base
const ll m = 1e9 + 7; // mod
void compute_hash(string const& s, ll id) // precomputes hash_val
{
    // hash_val[id][0] = s[0] - 'a' + 1;
    for (ll i = 0; i < (ll)s.size(); i++)
    {
        // hash_val[id][i] = (hash_val[id][i - 1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        hash_val[id][i] = ((s[i] - 'a' + 1) * p_pow[i]) % m;
    }
}
void powCalc(ll n) // precomputes p_pow[] and hash_val[]
{
    p_pow[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        p_pow[i] = (p * p_pow[i - 1]) % m;
        modIn[i]  =  modInverse(p_pow[i], m);
    }
}
ll ara[N],tree[2][4*N];
void build(ll node, ll b, ll e, ll id)
{
    if(b==e)
    {
        tree[id][node]=hash_val[id][b];
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    build(left,b,mid,id);
    build(right,mid+1,e,id);
    // modify this
    tree[id][node]=(tree[id][left]+tree[id][right])%m;
}
ll query(ll node, ll b, ll e, ll i, ll j, ll id)
{
    if(b>e || i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[id][node];
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j,id);
    ll p2=query(right,mid+1,e,i,j,id);
    return (p1+p2)%m;
}
void update(ll node, ll b, ll e, ll i, ll value, ll id)
{
    if(b>e || i>e || i<b)
    {
        return;
    }
    if(b==i && e==i)
    {
        tree[id][node]=value;
        return;
    }
    ll left=node*2;
    ll right=node*2+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,value,id);
    update(right,mid+1,e,i,value,id);
    tree[id][node]=(tree[id][left]+tree[id][right])%m;
}
ll query_hash(ll l, ll r, ll n, ll id) // calculates hash value of substring in range [l, r]
{
    if (r < l)
    {
        return 0;
    }
    if (l == 0)
    {
        return query(1,0,n-1,0,r,id);
    }
    else
    {
        return ((((query(1,0,n-1,0,r,id) - query(1,0,n-1,0,l-1,id)) + m) % m) * modIn[l]) % m;
    }
}
ll getHasVal(ll i, char c)
{
    ll val=((c-'a'+1)*p_pow[i])%m;
    return val;
}
void printTree(ll n)
{
    for(ll i=0; i<=4*n; i++) cout<<tree[0][i]<<", "; cout<<endl;
    for(ll i=0; i<=4*n; i++) cout<<tree[1][i]<<", "; cout<<endl;
}
void test()
{
    ll n,m; cin>>n>>m;
    string s0; cin>>s0;
    string s1=s0;
    reverse(all(s1));
    powCalc(n);
    compute_hash(s0,0);
    compute_hash(s1,1);
    build(1,0,n-1,0);
    build(1,0,n-1,1);
    // for(ll i=0; i<n; i++) cout<<hash_val[0][i]<<", "; cout<<endl;
    // for(ll i=0; i<n; i++) cout<<hash_val[1][i]<<", "; cout<<endl;
    // printTree(n);
    // ll val=query_hash(0,1,n,0);
    // debx(val);
    while(m--)
    {
        ll type; cin>>type;
        if(type==1)
        {
            ll index; cin>>index;
            ll tmp=index;
            index--;
            char c; cin>>c;
            ll val=getHasVal(index,c);
            update(1,0,n-1,index,val,0);
            index = n-tmp+1;
            index--;
            val=getHasVal(index,c);
            update(1,0,n-1,index,val,1);
            // printTree(n);
        }
        else
        {
            ll l,r; cin>>l>>r;
            l--,r--;
            ll mid=(l+r)/2;
            ll bam=mid-l,dan=r-mid;
            ll mid1;
            if(bam==dan)
            {
                mid1 = n-mid-1;
            }
            else
            {
                mid1 = n-mid-2;
            }
            ll l1=mid1-bam;
            ll r1=mid1+dan;
            // debx(mid1);
            // deb2(l1,r1);
            ll val0 = query_hash(l,r,n,0);
            ll val1 = query_hash(l1,r1,n,1);
            // deb2(val0,val1);
            if(val0==val1)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }
        }
    }
}
