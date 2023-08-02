2D BFS:
bool valid(int x, int y)
{
    return (x>=1&&x<=row&&y>=1&&y<=col);
}
ll bfs(pll src, pll des)
{
    memset(level,-1,sizeof(level));
    // for(ll i=1; i<=row; i++)
    // {
    //     for(ll j=1; j<=col; j++)
    //     {
    //         level[i][j]=inf;
    //     }
    // }
    queue<pll> q;
    q.push(src);
    level[src.ff][src.ss]=0;
    while(!q.empty())
    {
        pll pr=q.front();
        ll x=pr.ff, y=pr.ss;
        q.pop();
        if(x==des.ff && y==des.ss)
        {
            return level[des.ff][des.ss];
        }
        for(ll i=0; i<4; i++)
        {
            ll xx=x+dx[i], yy=y+dy[i];
            // if(valid(xx,yy) && level[x][y]+1<level[xx][yy])
            if(valid(xx,yy) && level[xx][yy]==-1)
            {
                q.push(mp(xx,yy));
                level[xx][yy]=level[x][y]+1;
            }
        }
    }
    return level[des.ff][des.ss];
}
