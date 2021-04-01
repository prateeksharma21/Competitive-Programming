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
   vector<int> A(n);
   f(i,0,n){
      cin >> A[i];
   } 
   int L = 0, R = n-1;
   int mv = 0;
   int sma = 0,smb = 0,pa = 0,pb = 0;
   while(L<=R){
      int cur = 0;
      while(L<R+1 and cur<=pb){
         cur += A[L];
         L++;
      }
      sma += cur;
      pa = cur;
      mv++;
      cur = 0;
      while(L-1<R and cur<=pa){
         cur += A[R];
         R--;
      }
      smb += cur;
      pb = cur;
      mv++;
   }
   cout << mv << ' ' << sma << ' ' << smb << '\n';
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
