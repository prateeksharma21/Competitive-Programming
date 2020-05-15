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
const int MOD = 1e9+7, N = 2e5 + 10; 

int A[N];
int P[N];
map<int,int> C;

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   f(i,1,n+1){
      cin >> A[i];
      if(A[i]>0){
         A[i] = 1;
      }else{
         A[i] = -1;
      }
   }
   P[1] = A[1];
   C[P[1]]++;
   f(i,2,n+1){
      P[i] = P[i-1]*A[i];
      C[P[i]]++;
   }
   int pos = 0;
   f(i,1,n+1){
      if(A[i] == 1){
         pos += C[P[i]];
      }else{
         pos += C[-P[i]];
      }
      C[P[i]]--;
   }
   cout << n*(n+1)/2-pos << ' ' << pos << '\n';
   return 0;
} 