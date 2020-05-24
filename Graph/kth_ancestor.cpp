int parent[N][LG];

void dfs(int u, int p = 0)
{
    parent[u][0] = p;
    for (auto &v : G[u])
    {
        if (v != p)
        {
            dfs(v, u);
        }
    }
}

void precompute()
{
    f(j, 1, LG)
    {
        f(i, 1, n + 1)
        {
            if (parent[i][j - 1])
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int kth(int u, int d)
{
    for (int j = LG - 1; j >= 0; j--)
    {
        if ((1ll << j) <= d)
        {
            u = parent[u][j];
            d -= (1ll << j);
        }
    }
    return u;
}