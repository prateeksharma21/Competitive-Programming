#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define int ll
using ld = long double;
using ll = long long;
using pii = pair<int,int>;
const int MOD = 1e9+7, N = 1e5 + 10; 

vector<vector<ld>> A;
vector<vector<bool>> mark;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin >> tt;
   f(_,1,tt+1){
      cout << "Case #" << _ << ": ";
      int w,h,l,u,r,d;
      cin >> w >> h >> l >> u >> r >> d;
      ld ans = 1;
      if(w <=300 and h <= 300){
         A = vector<vector<ld>>(w+1,vector<ld>(h+1));
         mark = vector<vector<bool>>(w+1,vector<bool>(h+1));
         f(i,l,r+1){
            f(j,u,d+1){
               mark[i][j] = true;
            }
         }
         A[1][1] = 1.00;
         f(i,2,w+1){
            if(mark[i][1]) break;
            A[i][1] = A[i-1][1]/2;
         }
         f(i,2,h+1){
            if(mark[1][i]) break;
            A[1][i] = A[1][i-1]/2;
         }
         f(i,2,w+1){
            f(j,2,h+1){
               if(mark[i][j]) continue;
               if(i == w and j == h){
                  A[i][j] = A[i-1][j]+A[i][j-1];
               }else if(i == w){
                  A[i][j] = A[i-1][j]/2+A[i][j-1];
               }else if(j == h){
                  A[i][j] = A[i-1][j]+A[i][j-1]/2;
               }else{
                  A[i][j] = (A[i-1][j]+A[i][j-1])/2;
               }
            }
         }
         ld ans = 0;
         cout << setprecision(14) << fixed << A[w][h] << '\n';
         continue;
      }
      vector<ld> A(w+1);
      vector<ld> B(h+1);
      if(l!=1){
         int sm = l-2;
         ld a = 1;
         // f(i,0,sm) a/=2;         
         int v = 1;
         f(i,1,l){
            a *= v;
            v++;
         }
         f(i,0,sm) a/=2;         
         f(i,1,l) a/=i;
         B[1] = a;
         f(i,2,h+1){
            if(l!=2){
               a /= (i-1);
               a *= (i+l-3);
            }
            a /= 2;
            B[i] = a;
         }
         f(i,u,d+1){
            // cout << B[i] << ' ';
            ans -= B[i]/2;
         }
         // cout << '\n';
      }
      if(u!=1){
         int sm = u-2;
         ld a = 1;
         // f(i,0,sm) a/=2;
         int v = 1;
         f(i,1,u){
            a *= v;
            v++;
            a /= i;
         }
         f(i,0,sm) a/=2;
         A[1] = a;
         f(i,2,w+1){
            if(u!=2){
               a /= (i-1);
               a *= (i+u-3);
            }
            a /= 2;
            A[i] = a;
         }
         f(i,l,r+1){
            // cout << A[i] << ' ';
            ans -= A[i]/2;
         }
         // cout << '\n';
      }
      cout << setprecision(14) << fixed<< ans << '\n';
   }
   return 0;
}