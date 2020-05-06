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
   string s;
   cin >> s;
   set<char> S;
   vector<int> cnt(26);
   for(auto &e : s){
      cnt[e-'a']++;
      S.insert(e);
   }
   vector<string> ans(k);
   sort(all(s));
   if(S.size() == 1){
      f(i,0,n){
         ans[i%k].pb(s[i]);
      }
      string R = ans[0];
      f(i,1,k){
         R = max(R,ans[i]);
      }
      cout << R << '\n';
   }else if(S.size() == 2){
      auto c = *s.begin();
      if(cnt[c-'a'] == k){
         f(i,0,n){
            ans[i%k].pb(s[i]);
         }
         string R = ans[0];
         f(i,1,k){
            R = max(R,ans[i]);
         }
         cout << R << '\n';
      }else{
         f(i,0,k){
            ans[i%k].pb(s[i]);
         }
         f(i,k,n){
            ans[0].pb(s[i]);
         }
         string R = ans[0];
         f(i,1,k){
            R = max(R,ans[i]);
         }
         cout << R << '\n';
      }
   }else{
      f(i,0,k){
         ans[i%k].pb(s[i]);
      }
      f(i,k,n){
         ans[0].pb(s[i]);
      }
      string R = ans[0];
      f(i,1,k){
         R = max(R,ans[i]);
      }
      cout << R << '\n';
   }


   // f(i,0,k){
   //    ans[i%k].pb(s[i]);
   // }
   // if(cnt[s[0]-'a']<k){
   //    f(i,k,n){
   //       ans[0].pb(s[i]);
   //    }
   //    string R = ans[0];
   //    f(i,1,k){
   //       R = max(R,ans[i]);
   //    }
   //    cout << R << '\n';
   //    return;
   // }
   // cnt[s[0]-'a'] -= k;
   // if(!cnt[s[0]-'a'] or cnt[s[0]-'a'] == n-k){
   //    S.erase(s[0]);
   // }
   // if(S.size() == 1 or S.empty()){
   //    f(i,k,n){
   //       ans[i%k].pb(s[i]);
   //    }
   //    string R = ans[0];
   //    f(i,1,k){
   //       R = max(R,ans[i]);
   //    }
   //    cout << R << '\n';
   //    return;  
   // }else{
   //    f(i,k,n){
   //       ans[0].pb(s[i]);
   //    }
   //    string R = ans[0];
   //    f(i,1,k){
   //       R = max(R,ans[i]);
   //    }
   //    cout << R << '\n';
   //    return; 
   // }
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