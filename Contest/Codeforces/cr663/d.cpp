#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin >> n >> m;

   vector<vector<char>> A(n,vector<char>(m));
   vector<vector<int>> V(n,vector<int>(m));

   for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
         cin >> A[i][j];
         V[i][j] = A[i][j]-'0';
      }
   }

   if(n >= 4 and m >= 4){
      cout << "-1\n";
      return 0;
   }

   if(n == 1 or m == 1){
      cout << "0\n";
      return 0;
   }

   auto comp11 = [&](vector<int> A){
      vector<int> R1 = {1,0}, R2 = {0,1};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 2; ++i){
         c1 += (R1[i]!=A[i]);
         c2 += (R2[i]!=A[i]);
      }
      return min(c1,c2);
   };

   auto comp12 = [&](vector<int> A){
      vector<int> R1 = {0,0}, R2 = {1,1};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 2; ++i){
         c1 += (R1[i]!=A[i]);
         c2 += (R2[i]!=A[i]);
      }
      return min(c1,c2);
   };


   if(n == 2){
      int c1 = 0, c2 = 0;
      for(int j = 0; j < m; ++j){
         vector<int> tt = {V[0][j],V[1][j]};
         if(j & 1){
            c1 += comp11(tt);
            c2 += comp12(tt);
         }else{
            c1 += comp12(tt);
            c2 += comp11(tt);
         }
      }
      cout << min(c1,c2) << '\n';
      return 0;
   }

   auto comp1 = [&](vector<int> A){
      vector<int> R1 ={0,0,0}, R2 = {1,1,1};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 3; ++i){
         c1 += (R1[i]!=A[i]);
         c2 += (R2[i]!=A[i]);
      }
      return min(c1,c2);
   };

   auto comp2 = [&](vector<int> A){
      vector<int> R1 ={0,1,0}, R2 = {1,0,1};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 3; ++i){
         c1 += R1[i]!=A[i];
         c2 += R2[i]!=A[i];
      }
      return min(c1,c2);  
   };

   auto comp3 = [&](vector<int> A){
      vector<int> R1 ={0,0,1}, R2 = {1,1,0};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 3; ++i){
         c1 += R1[i]!=A[i];
         c2 += R2[i]!=A[i];
      }
      return min(c1,c2);  
   };

   auto comp4 = [&](vector<int> A){
      vector<int> R1 ={0,1,1}, R2 = {1,0,0};
      int c1 = 0,c2 = 0;
      for(int i = 0; i < 3; ++i){
         c1 += R1[i]!=A[i];
         c2 += R2[i]!=A[i];
      }
      return min(c1,c2);  
   };


   int c3 = 0, c4 = 0;
   int c1 = 0, c2 = 0;
   for(int j = 0; j < m; ++j){
      vector<int> tt = {V[0][j],V[1][j],V[2][j]};
      if(j & 1){
         c1 += comp1(tt);
         c2 += comp2(tt);
         c3 += comp3(tt);
         c4 += comp4(tt);
      }else{
         c1 += comp2(tt);
         c2 += comp1(tt);
         c3 += comp4(tt);
         c4 += comp3(tt);
      }
   }

   cout << min({c1,c2,c3,c4}) << '\n';
   return 0;
}