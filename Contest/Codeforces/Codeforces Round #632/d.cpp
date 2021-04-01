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
const int MOD = 1e9+7, N = 3000000; 

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,k;
   cin >> n >> k;
   string s;
   cin >> s;
   int sum = 0;
   string fin = s;
   vector<int> ans;
   int cnt = 0;
   vector<int> child[k+10];
   int timer = 0;
   while(1){
      int c = 0;
      vector<int> op;
      f(i,0,n-1){
         if(fin[i] == 'R' and fin[i+1] == 'L'){
            swap(fin[i],fin[i+1]);
            op.pb(i);
            i++;
            c++;
         }
      }
      if(!c){
         break;
      }
      sum += c;
      ans.pb(c);
      if(ans.size()>k){
         cout << "-1\n";
         return 0;
      }
      for(auto &o : op){
         child[timer].pb(o+1);
      }
      timer++;
   }
   if(ans.size()>k){
      cout << "-1\n";
      return 0;
   }
   if(sum < k){
      cout << "-1\n";
      return 0;
   }
   int sz = ans.size();
   int cur = 0;
   f(i,0,sz){
      cur += ans[i];
      if(cur+sz-i-1<k){
         for(auto &e : child[i]){
            cout << "1 " << e << '\n';
         }
      }else{
         int have = cur-ans[i]+sz-i-1;
         int req = k-have;
         req--;
         int dd = 0;
         f(j,0,req){
            cout << "1 " << child[i][j] << '\n';
         }
         cout << ans[i]-req << ' ';
         f(j,req,child[i].size()){
            cout << child[i][j] << ' ';
         }
         cout << '\n';
         f(k,i+1,sz){
            cout << child[k].size() << ' ';
            for(auto &e : child[k]){
               cout << e << ' ';
            }
            cout << '\n';
         }
         return 0;
      }
   }
   return 0;
} 