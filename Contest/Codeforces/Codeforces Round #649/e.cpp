#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ll = long long;
const int MOD = 1e9+7, N = 2050; 

int n;
int ans[N][N];
int q = 0;
vector<pair<int, int>> Q;
vector<int> A;

int get(){
   return rand()%n;
}

int query(int x,int y){
   if(ans[x][y] != -1) return ans[x][y];
   q++;
   cout << "? "<< x+1 << ' ' << y+1 << endl;
   cin >> ans[x][y];
   ans[y][x] = ans[x][y];
   Q.pb({x,y});
   return ans[x][y];
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n;
   memset(ans,-1,sizeof ans);
   f(i,0,n){
      A.pb(i);
   }
   srand(MOD);
   while(A.size() > 1){
      vector<int> B;
      int x,y;
      for(auto &c : A){
         bool ok = true;
         f(i,0,n){
            if(ans[c][i] == -1) continue;
            f(j,0,n){
               if(ans[i][j] == -1) continue;
               if((ans[c][i] & ans[i][j]) != ans[c][i]){
                  ok = false;
               }
            }
         }

         if(!ok) continue;

         if(q >= 1024){
            while(1){
               int v = rand()%(int)Q.size();
               x = Q[v].F;
               y = Q[v].S;
               if(x != c and y != c and x != y) break;
            }
         }else{
            while(1){
               x = get();
               y = get();
               if(x != y and x != c and y != c) break;
            }
         }
         int ff,ss;
         if(ans[c][x] != -1){
            ff = ans[c][x];
         }else if(ans[c][x] != -1){
            ff = ans[c][x];
         }else{
            ff = query(c,x);
         }
         ss = query(x,y);
         if((ff&ss) == ff){
            B.pb(c);
         }
      }
      A = B;
   }
   int ind = A[0];
   vector<int> R;
   f(i,0,n){
      if(i == ind){
         R.pb(0);
      }else{
         R.pb(query(ind,i));
      }
   }
   cout << "! ";
   for(auto &e : R){
      cout << e << ' ';
   }
   cout << endl;
   return 0;
} 