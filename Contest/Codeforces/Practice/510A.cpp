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
   int n,m;
   cin >> n >> m;
   vector<vector<char>> A(n,vector<char>(m,'#'));
   int c = 1;
   f(i,1,n){
      if(c&1){
         f(j,0,m-1){
            A[i][j] = '.';
         }
      }else{
         f(j,1,m){
            A[i][j] = '.';
         }
      }
      i++;
      c ^= 1;
   }
   f(i,0,n){
      f(j,0,m){
         cout << A[i][j];
      }
      cout << '\n';
   }
   return 0;
}