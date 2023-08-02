vector<ll> graph[100000+5];
bool vis[100000+5];
bool vis2[100000+5];
ll n,m;
bool cycle=0;
void cycleDFS(ll u)
{
    vis[u]=1;
    vis2[u]=1;
    for(auto v: graph[u])
    {
        if(!vis[v])
        {
            cycleDFS(v);
        }
        else if(vis2[v])
        {
            cycle=1;
        }
    }
    vis2[u]=0;
}
