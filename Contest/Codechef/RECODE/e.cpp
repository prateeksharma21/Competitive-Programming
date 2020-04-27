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
   vector<int> ind;
   vector<int> bit(32);
   int val = 0;
   f(i,0,n){
      cin >> A[i];
      if((A[i]|k)!=k){
         ind.pb(i);
         continue;
      }else{
         f(j,0,32){
            if((1ll<<j)&A[i]) bit[j]++;
         }
      }
      val |= A[i];
   } 
   if(val<k){
      cout << "-1\n";
      return;
   }
   int sz = ind.size();
   f(i,0,sz){
      if(ind[i]+1 == ind[(i+1)%sz]){
         cout << "-1\n";
         return;
      }
   }
   if(!ind.empty() and ind.front() == 0 and ind.back() == n-1){
      cout << "-1\n";
      return;
   }
   vector<int> vis(n);
   if(ind.size()){
      for(auto &e : ind){
         vis[e] = 1;
         cout << e+1 << ' ';
      }
      f(i,0,n){
         int cur = (ind.front()+i)%n;
         if(!vis[cur]){
            cout << cur+1 << ' ';
         }
      }
      cout << '\n';
      return;
   }
   int yes = 0;
   f(i,0,n){
      int c = 1;
      f(j,0,32){
         if((1ll<<j)&A[i]){
            if(bit[j] == 1){
               c = 0;
               break;
            }
         }
      }
      if(c){
         yes = 1;
         f(j,0,n){
            cout << (i+j)%n+1 << ' ';
         }
         cout << '\n';
         break;
      }
   }
   if(!yes){
      cout << "-1\n";
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
