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
   int n;
   cin >> n;
   if(n==1){
      cout << "1\n";
      return 0;
   }
   if(n<4){
      cout << "NO SOLUTION\n";
      return 0;
   }
   if(n == 4){
      cout << "2 4 1 3\n";
      return 0;
   }
   vector<int> ans(n+1);
   int c = 1;
   f(i,1,n+1){
      ans[i] = c++;
      i++;
   }
   f(i,2,n+1){
      ans[i] = c++;
      i++;
   }
   f(i,1,n+1){
      cout << ans[i] << ' ';
   }
   cout << '\n';
   return 0;
}