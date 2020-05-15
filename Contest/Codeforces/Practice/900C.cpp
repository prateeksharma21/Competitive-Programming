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
   int n;
   cin >> n;
   vector<int> A(n);
   multiset<int> s;
   f(i,0,n){
      cin >> A[i];
      s.insert(A[i]);
   }
   multiset<int> t;
   int k = 0;
   f(i,0,n-1){
      t.insert(A[i]);
      s.erase(s.find(A[i]));
      int c = 0;
      c |= (*s.rbegin()>A[i] and *t.rbegin()>A[i]);
      if(c){
         cout << 3 << '\n';
         for(int j=i-1;j>=0;j--){
            if(A[j]>A[i]){
               cout << j+1 << ' ';
               break;
            }
         }
         cout << i+1 << ' ';
         f(j,i+1,n){
            if(A[j]>A[i]){
               cout << j+1 << ' ';
               break;
            }  
         }
         return 0;
      }
      c |= (*s.begin()<A[i] and *t.begin()<A[i]);
      if(c){
         cout << 3 << '\n';
         for(int j=i-1;j>=0;j--){
            if(A[j]<A[i]){
               cout << j+1 << ' ';
               break;
            }
         }
         cout << i+1 << ' ';
         f(j,i+1,n){
            if(A[j]<A[i]){
               cout << j+1 << ' ';
               break;
            }  
         }
         return 0;
      }
   }
   cout << 0;
   return 0;
}