#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   vector<int> C(k);
   for(auto &e : s) C[e-'A']++;
   int mn = 1e18;
   for(auto &e : C) mn = min(mn,e);
   cout << mn*k;
   return 0;
}