#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10;
const int M = 1e3+1;

vector<int> F[M];

void test(){
   int n;
   cin >> n;
   vector<int> A(n);
   set<pair<int, int>> S[M];
   int c1 = 0;
   for(int i = 0; i < n; ++i){
      cin >> A[i];
      c1 += (A[i]==1);
   }
   sort(all(A),greater<int>());
   for(int i = 1; i < n; ++i){
      for(int f : F[A[i]]){
         S[f].insert({A[i],i});
      }
   }
   int prv = A[0];
   vector<int> R = {A.front()};
   vector<int> done(n);
   done[0] = 1;
   while(true){
      int c = 0;
      for(int v : F[prv]){
         if(!S[v].empty()){
            auto k = *S[v].begin();
            R.push_back(k.first);
            for(int u : F[A[k.second]]){
               S[u].erase({A[k.second],k.second});
            }
            prv =v;
            c = 1;
            break;
         }
      }
      if(c == 0){
         break;
      }
   }
   for(int i = 1; i < M; ++i){
      while(!S[i].empty()){
         auto k = *S[i].begin();
         R.push_back(k.first);
         for(int u : F[A[k.second]]){
            S[u].erase({A[k.second],k.second});
         }
      }
   }
   for(int i : R){
      cout << i << ' ';
   }
   for(int i = 0; i < c1; ++i){
      cout << 1 << ' ';
   }
   cout << '\n';
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   for(int i = 2; i < M; i++){
      for(int j = i; j < M; j += i){
         F[j].push_back(i);
      }
   }
   for(int i = 2; i < M; ++i){
      reverse(all(F[i]));
   }
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
