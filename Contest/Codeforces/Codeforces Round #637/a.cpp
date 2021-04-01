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
   int n;
   cin >> n;
   vector<int> a(n+1);
   vector<int> pos(n+1);
   vector<int> done(n+1);
   f(i,1,n+1){
      int x;
      cin >> x;
      a[i] = x;
      pos[x] = i;
   }
   vector<int> res(n+1);
   int lst = n+1;
   f(i,1,n+1){
      int c = i;
      f(j,pos[i],lst){
         res[j] = c++;
      }
      lst = min(lst,pos[i]);
   }
   if(res == a){
      cout << "Yes\n";
   }else{
      cout << "No\n";
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
