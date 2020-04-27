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
const int MOD = 1e9+7, N = 6e5 + 10; 
const int LG = log2(N)+1;

int MX[N][LG];

int get(int l,int r){
   int j = log2(r-l+1);
   return min(MX[l][j],MX[r-(1<<j)+1][j]);
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<pii> A(n);
   map<int,int> hsh;
   set<int> s;
   f(i,0,n){
      cin >> A[i].F >> A[i].S;
      s.insert(A[i].F);
      s.insert(A[i].S);
      s.insert(A[i].S+1);
   }
   int c = 0;
   for(auto &e : s){
      hsh[e] = c++;
   }
   vector<int> sm(c+2);
   f(i,0,n){
      A[i].F = hsh[A[i].F];
      A[i].S = hsh[A[i].S];
      ++sm[A[i].F];
      --sm[A[i].S+1];
   }
   int cur = 0;
   f(i,0,c+2){
      cur += sm[i];
      MX[i][0] = cur;
   }
   f(j,1,LG){
      for(int i=0;i+(1<<j)<=c+2;i++){
         MX[i][j] = min(MX[i][j-1],MX[i+(1<<(j-1))][j-1]);         
      }
   }
   int ans = 0;
   f(i,0,n){
      int mx = get(A[i].F,A[i].S);
      if(mx!=1){
         cout << i+1 << '\n';
         return 0;
      }
   }
   cout << "-1\n";
   return 0;
} 