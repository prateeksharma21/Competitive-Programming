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

int cnt[N][26];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vector<string> s(n+1);
   vector<int> pos[26];
   f(i,1,n+1){
      cin >> s[i];
      f(j,0,26){
         cnt[i][j] = cnt[i-1][j];
      }
      for(auto &e : s[i]){
         cnt[i][e-'a']++;
         pos[e-'a'].pb(i);
      }
   }
   int q;
   cin >> q;
   while(q--){
      string t;
      cin >> t;
      vector<int> c(26);
      for(auto &e : t){
         c[e-'a']++;
      }
      int cn = 1;
      f(i,0,26){
         if(pos[i].size()<c[i]) cn = 0;
      }
      if(!cn){
         cout << "-1\n";
         continue;
      }
      vector<int> cur(26);
      int ans = 1e9;
      f(i,1,n+1){
         int lst = 0,chk = 1;
         f(j,0,26){
            auto k1 = lower_bound(all(pos[j]),i)-pos[j].begin();
            if(k1+c[j]-1<pos[j].size()){
               lst = max(lst,pos[j][k1+c[j]-1]);
            }else if(c[j]){
               chk = 0;

            }
         }
         if(chk)
            ans = min(ans,lst-i+1);
         // cout << chk << '\n';
      }
      cout << ans << '\n';
   }
   return 0;
} 