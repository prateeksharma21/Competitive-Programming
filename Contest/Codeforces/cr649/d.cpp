// https://codeforces.com/contest/1325/submission/73250558

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
const int mxN=1e5;
int n, m, sq, d[mxN], par[mxN];
vector<int> adj[mxN], ord;
bool vis[mxN], bad[mxN];

void ans2(int u, int v) {
    cout << "2\n" << d[u]-d[v]+1 << "\n";
    while(1) {
        cout << u+1 << " ";
        if(u==v)
            break;
        u=par[u];
    }
    exit(0);
}
void dfs(int u=0, int p=-1) {
    if(~p) {
        adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
        d[u]=d[p]+1;
    }
    par[u]=p;
    vis[u]=1;
    for(int v : adj[u]) {
        if(vis[v]) {
            if(d[u]>d[v]&&d[u]-d[v]+1<=sq) {
                ans2(u, v);
            }
        } else
            dfs(v, u);
    }
    ord.push_back(u);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> sq;
    int sq1 = (sq+1)/2;
    for(int i=0, u, v; i<m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    cout << "1\n";
    for(int i=0, j=0; j< (sq+1)/2; ++i) {
        if(bad[ord[i]])
            continue;
        cout << ord[i]+1 << " ";
        for(int k : adj[ord[i]])
            bad[k]=1;
        if(~par[ord[i]])
            bad[par[ord[i]]]=1;
        ++j;
    }
}