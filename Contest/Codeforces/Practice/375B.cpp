#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 
#ifdef HOME
#include "/home/prateek2112/print.cpp"
#else
#define debug(...) 21
#endif

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;
   vector<vector<int>> A(n,vector<int>(m)),pre(n,vector<int>(m));
   f(i,0,n){
      string s; cin >> s;
      f(j,0,m){
         A[i][j] = s[i][j]-'0';
      }
   }
   
   return 0;
}