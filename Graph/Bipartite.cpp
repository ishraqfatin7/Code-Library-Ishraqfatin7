int edge[N][N];
int vis[N];
int color[N];
int m, n;

bool dfs(int u)
{
    for (int i = 0; i < n; i++)
    {
        if (edge[u][i])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                color[i] = !color[u];
                dfs(i);
            }
            else if (color[i] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}
//Bipartite-matching:
const ll N=105;
ll Left[N],Right[N],seen[N];
vll graph[N];
ll n,m;
bool kuhn(ll u)
{
    for(auto v: graph[u])
    {
        if(seen[v]) continue;
        seen[v]=1;
        if(Right[v]==-1 || kuhn(Right[v]))
        {
            Right[v]=u;
            Left[u]=v;
            return true;
        }
    }
    return false;
}
void bipartite_matching()
{
    memo(Left,-1);
    memo(Right,-1);
    ll cnt=0;
    for(ll i=0; i<m; i++) // m = left side er total nodes
    {
        memo(seen,0);
        if(kuhn(i)) cnt++;
    }
    cout<<cnt<<endl;
}
