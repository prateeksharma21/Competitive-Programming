// C++ program to print the number of elements 
// greater than k in a subarray of range L-R. 
#include <bits/stdc++.h> 
using namespace std; 

// Structure which will store both 
// array elements and queries. 
struct node { 
   int pos; 
   int l; 
   int r; 
   int val; 
}; 

// Boolean comparator that will be used 
// for sorting the structural array. 
bool comp(node a, node b) 
{ 
   // If 2 values are equal the query will 
   // occur first then array element 
   if (a.val == b.val) 
      return a.l > b.l; 

   // Otherwise sorted in descending order. 
   return a.val > b.val; 
} 

// Updates the node of BIT array by adding 
// 1 to it and its ancestors. 
void update(int* BIT, int n, int idx) 
{ 
   while (idx <= n) { 
      BIT[idx]++; 
      idx += idx & (-idx); 
   } 
} 
// Returns the count of numbers of elements 
// present from starting till idx. 
int query(int* BIT, int idx) 
{ 
   int ans = 0; 
   while (idx) { 
      ans += BIT[idx]; 

      idx -= idx & (-idx); 
   } 
   return ans; 
} 

// Function to solve the queries offline 
void solveQuery(int arr[], int n, int QueryL[], 
            int QueryR[], int QueryK[], int q) 
{ 
   // create node to store the elements 
   // and the queries 
   node a[n + q + 1]; 
   // 1-based indexing. 

   // traverse for all array numbers 
   for (int i = 1; i <= n; ++i) { 
      a[i].val = arr[i - 1]; 
      a[i].pos = 0; 
      a[i].l = 0; 
      a[i].r = i; 
   } 

   // iterate for all queries 
   for (int i = n + 1; i <= n + q; ++i) { 
      a[i].pos = i - n; 
      a[i].val = QueryK[i - n - 1]; 
      a[i].l = QueryL[i - n - 1]; 
      a[i].r = QueryR[i - n - 1]; 
   } 

   // In-built sort function used to 
   // sort node array using comp function. 
   sort(a + 1, a + n + q + 1, comp); 

   // Binary Indexed tree with 
   // initially 0 at all places. 
   int BIT[n + 1]; 

   // initially 0 
   memset(BIT, 0, sizeof(BIT)); 

   // For storing answers for each query( 1-based indexing ). 
   int ans[q + 1]; 

   // traverse for numbers and query 
   for (int i = 1; i <= n + q; ++i) { 
      if (a[i].pos != 0) { 

         // call function to returns answer for each query 
         int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1); 

         // This will ensure that answer of each query 
         // are stored in order it was initially asked. 
         ans[a[i].pos] = cnt; 
      } 
      else { 
         // a[i].r contains the position of the 
         // element in the original array. 
         update(BIT, n, a[i].r); 
      } 
   } 
   // Output the answer array 
   for (int i = 1; i <= q; ++i) { 
      cout << (QueryR[i-1]-QueryL[i-1]+1)-ans[i] << ' '; 
   } 
} 

// Driver Code 
int main() 
{
   int tt;
   cin >> tt;
   while(tt--){
      int n,q;
      cin >> n >> q;
      vector<pair<int,int>> A;
      for(int i=0;i<n;i++){
         int x,y;
         cin >> x >> y;
         if(x>=y){
            A.push_back({x-y,x+y});
         }
      }
      n = A.size();
      sort(A.begin(),A.end());
      int QueryL[q],QueryR[q],QueryK[q];
      for(int i=0;i<q;i++){
         int l,r;
         cin >> l >> r;
         auto k = lower_bound(A.begin(),A.end(),make_pair(l,-1))-A.begin();
         QueryL[i] = k+1;
         QueryR[i] = n;
         QueryK[i] = r;
      }
      int arr[n];
      for(int i=0;i<n;i++){
         arr[i] = A[i].second;
      }
      solveQuery(arr,n,QueryL,QueryR,QueryK,q);
   }

   return 0; 
} 
