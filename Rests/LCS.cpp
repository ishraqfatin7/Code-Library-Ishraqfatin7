const int N=105;
int dp[N][N];
string a,b;
int na,nb;
char lcs[N];
int cnt=0;
set<string> st;
void dfs(int i, int j, int k)
{
    if(i<=0 || j<=0)
    {
        string s;
        for(int ii=k; ii>=1; ii--)
        {
            s+=lcs[ii];
        }
        st.insert(s);
        return;
    }
    if(a[i]==b[j])
    {
        lcs[k+1]=a[i];
        dfs(i-1,j-1,k+1);
    }
    else if(dp[i][j-1]>dp[i-1][j])
    {
        dfs(i,j-1,k);
    }
    else if(dp[i-1][j]>dp[i][j-1])
    {
        dfs(i-1,j,k);
    }
    else
    {
        dfs(i-1,j,k);
        dfs(i,j-1,k);
    }
}
void solve()
{
    cin>>a>>b;
    na=(int)a.size(),nb=(int)b.size();
    a="."+a,b="."+b;
    for(int i=1; i<=na; i++)
    {
        for(int j=1; j<=nb; j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[na][nb]<<endl;
    dfs(na,nb,0);
}
