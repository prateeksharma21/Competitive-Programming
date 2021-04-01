#include<bits/stdc++.h>
using namespace std;

int main(){
   int tt;
   cin >> tt;
   while(tt--){
      int n;
      cin >> n;
      vector<int> A(n),C(n);
      int mx = 0;
      for(int i=0;i<n;i++){
         cin >> A[i];
         int d = i+A[i];
         if(d<0){
            d = (n-abs(d)%n)%n;
         }else{
            d = d%n;
         }
         C[d]++;
         mx = max(mx,C[d]);
      }
      cout << ((mx>=2)?"NO\n":"YES\n");
   }
}