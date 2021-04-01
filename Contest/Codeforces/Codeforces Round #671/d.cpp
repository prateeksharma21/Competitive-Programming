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
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> A(n);
   for(int &i : A){
      cin >> i;
   }
   sort(all(A));
   multiset<int> small,large;
   for(int i = 0; i < (n-1)/2; ++i){
      small.insert(A[i]);
      A[i] = 0;
   }
   for(int i = (n-1)/2; i < n; ++i){
      large.insert(A[i]);
      A[i] = 0;
   }
   for(int pos = 1; pos < n; pos += 2){
      if(small.empty() or large.empty()) break;
      int mn = *small.begin();
      auto k = large.upper_bound(mn);
      if(k == large.end()) break;
      if(pos == 1){
         if(next(k) != large.end() and pos+1 < n){
            A[pos] = mn;
            A[pos-1] = *k;
            A[pos+1] = *next(k);
            small.erase(small.begin());
            large.erase(next(k));
            large.erase(k);
         }else{
            break;
         }
      }else{
         int v = A[pos-1];
         if(v <= mn){
            large.insert(A[pos-1]);
            if(next(k) != large.end() and pos+1 < n){
               A[pos] = mn;
               A[pos-1] = *k;
               A[pos+1] = *next(k);
               small.erase(small.begin());
               large.erase(next(k));
               large.erase(k);
            }else{
               break;
            }
         }else{
            if(pos+1 < n){
               A[pos] = mn;
               A[pos+1] = *k;
               small.erase(small.begin());
               large.erase(k);
            }else{
               break;
            }
         }
      }
   }
   for(int i = 0; i < n; ++i){
      if(A[i] == 0){
         if(!small.empty()){
            A[i] = *small.begin();
            small.erase(small.begin());
         }else{
            A[i] = *large.begin();
            large.erase(large.begin());
         }
      }
   }
   int ans = 0;
   for(int i = 1; i < n-1; ++i){
      ans += (A[i] < A[i-1] and A[i] < A[i+1]);
   }
   cout << ans << '\n';
   for(int i : A){
      cout << i << ' ';
   }
   return 0;
}