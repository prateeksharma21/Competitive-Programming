#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int S[100001],R[100001], MX[100001];
vector<int> T[100001];


int32_t main(){
   cin >> n >> m;
   for(int i=0;i<n;i++){
      cin >> S[i] >> R[i];
      T[S[i]].push_back(R[i]);
   }
   for(int i=1;i<=m;i++){
      sort(T[i].begin(),T[i].end());
      reverse(T[i].begin(),T[i].end());
   }
   for(int i=1;i<=m;i++){
      int sm = 0;
      for(int j=0;j<T[i].size();j++){
         sm += T[i][j];
         if(sm < 0) break;
         MX[j+1] += sm;
      }
   }
   cout << *max_element(MX,MX+100001) << '\n';
   return 0;
}
