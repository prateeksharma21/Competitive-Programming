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

void test(){
   int n;
   cin >> n;
   vector<int> A(n);
   for(int i = 0; i < n; ++i){
      cin >> A[i];
   }
   vector<int> l(n);
   for(int i = 0; i < n; ++i){
      cin >> l[i];
   }
   vector<int> pos;
   vector<int> neg;
   for(int i = 0; i < n; ++i){
      if(l[i] == 0){
         if(A[i] >= 0){
            pos.push_back(A[i]);
         }else{
            neg.push_back(A[i]);
         }
      }
   }
   sort(all(pos));
   sort(all(neg));
   vector<int> pre;
   for(int i = 0; i < n; ++i){
      if(l[i] == 0){
         if(!pos.empty()){
            A[i] = pos.back();
            pos.pop_back();
         }else{
            A[i] = neg.back();
            neg.pop_back();
         }
      }
      cout << A[i] << ' '; 
      if(i == 0){
         pre.push_back(A[i]);
      }else{
         pre.push_back(pre.back()+A[i]);
      }
   }
   cout << '\n';
   debug(pre);
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}
