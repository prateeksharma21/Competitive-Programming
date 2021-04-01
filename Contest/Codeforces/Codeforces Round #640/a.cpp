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
   string n;
   cin >> n;
   vector<int> ans;
   f(i,0,n.length()){
      if(n[i]!='0'){
         ans.pb((n[i]-'0')*pow(10,(int)n.length()-i-1));
      }
   }
   cout<< ans.size() << '\n';
   for(auto &e : ans){
      cout << e << ' ';
   }
   cout << '\n';
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