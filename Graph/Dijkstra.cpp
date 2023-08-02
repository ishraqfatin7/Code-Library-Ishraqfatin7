int n, m;
vector<ar<int, 2>> adj[MAX_N];
vector<ll> dist;

void dijkstra(int s)
{
    dist.assign(n + 1, LINF);
    priority_queue<ar<ll, 2>, vector<ar<ll, 2>>, greater<ar<ll, 2>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto [v, w] : adj[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

//Second Shortest
ll dis1[n+5],disn[n+5];
    dij(1);
    for(ll i=1; i<=n; i++) dis1[i]=dis[i];
    dij(n);
    for(ll i=1; i<=n; i++) disn[i]=dis[i];
    ll minn2=inf;
    for(ll u=1; u<=n; u++)
    {
        for(auto v: graph[u])
        {
            ll dist=dis1[u]+disn[v.ss];
            dist+=v.ff;
            if(dist>dis1[n])
            {
                minn2=min(minn2,dist);
            }
        }
    }
    cout<<"Second shortest distance: "<<minn2<<endl;
