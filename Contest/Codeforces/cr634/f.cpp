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
const int MOD = 1e9+7, N = 1e6 + 10;
const int LG = 24;

vector<vector<char>> A,G;
vector<int> P,V,nP,total,black;
int n,m;

int find(int x,int y,char c){
   if(c == 'U') return (x-1)*m+y;
   if(c == 'D') return (x+1)*m+y;
   if(c == 'L') return x*m+(y-1);
   return x*m+(y+1);
}

void test(){
   cin >> n >> m;
   P = nP = V = total = black = vector<int>(n*m+10);
   A = G = vector<vector<char>>(n,vector<char>(m));
   f(i,0,n){
      f(j,0,m){
         cin >> G[i][j];
         V[i*m+j] = (G[i][j] == '0');
      }
   }
   f(i,0,n){
      f(j,0,m){
         cin >> A[i][j];
         P[i*m+j] = find(i,j,A[i][j]);
      }
   }
   n *= m;
   f(i,0,LG){
      f(i,0,n){
         nP[i] = P[P[i]];
      }
      P = nP;
   }
   f(i,0,n){
      total[P[i]]++;
      black[P[i]] += V[i];
   }
   int a1 = 0,a2 = 0;
   f(i,0,n){
      a1 += (total[i] > 0);
      a2 += (black[i] > 0);
   }
   cout << a1 << ' ' << a2 << '\n';
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
