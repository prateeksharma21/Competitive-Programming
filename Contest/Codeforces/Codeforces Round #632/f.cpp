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
const int MOD = 1e9+7, N = 5e5 + 1; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<int> fact(n+1,1);
   f(i,1,n+1){
      for(int j=2*i;j<=n;j+=i){
         fact[j] = i;
      }
   }
   sort(fact.begin()+1,fact.end());
   f(i,2,n+1){
      cout << fact[i] << ' ';
   }
   return 0;
} 