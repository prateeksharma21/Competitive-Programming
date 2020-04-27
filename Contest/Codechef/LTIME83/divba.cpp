#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int ll
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10;
 
void test(){
   int n,k;
   cin >> n >> k;
   vector<int> A(n);
   f(i,0,n) cin >> A[i];
   vector<int> pos[k];
   f(i,0,n){
      pos[i%k].pb(A[i]);
   }   
   f(i,0,k){
      sort(all(pos[i]));
   }
   vector<int> ptr(k);
   f(i,0,n){
      A[i] = pos[i%k][ptr[i%k]];
      ptr[i%k]++;
   }
   if(is_sorted(all(A))){
      cout << "yes\n";
   }else{
      cout << "no\n";
   }
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
