#ifdef Prateek
  #include "\Prateek.h"
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

int lps[N];
vector<int> prime;

void test(){
   int n;
   cin >> n;
   map<int, int> tot_cnt, cur_cnt;
   vector<int> A(n);
   for(int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      A[i] = x;
      while(lps[x]) {
         tot_cnt[lps[x]]++;
         x /= lps[x];
      }
   }
   for(int i = 0; i < n; ++i) {
      int x = A[i];
      bool ans = true;
      while(lps[x]) {
         ++cur_cnt[lps[x]];
         --tot_cnt[lps[x]];
         x /= lps[x];
      }
      for(int i : prime) {
         if(cur_cnt[i] and tot_cnt[i]) {
            ans = false;
            break;
         } 
      }
      if(ans) {
         cout << i+1 << '\n';
         return ;
      }
   }
   assert(false);
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   
   for(int i = 2; i < N; ++i) {
      if(lps[i] == 0) {
         lps[i] = i;
         prime.push_back(i);
         for(int j = i*i; j < N; j += i) {
            lps[j] = i;
         }         
      }
   }

   cin >> tt;
   f(i,0,tt) test();   
   return 0;
}