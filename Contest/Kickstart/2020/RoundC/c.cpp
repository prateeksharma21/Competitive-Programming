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
const int MOD = 1e9+7, N = 2e7;
 
int findSubarraySum(vector<int> &arr, int n, int sum) { 
    unordered_map<int, int> prevSum; 
    int res = 0; 
    int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == sum)  
            res++;        
        if (prevSum.find(currsum - sum) !=  
                                  prevSum.end())  
            res += (prevSum[currsum - sum]); 
        prevSum[currsum]++; 
    } 
  
    return res; 
} 

int maxSubArraySum(vector<int> &a, int size) 
{ 
   int max_so_far = a[0]; 
   int curr_max = a[0]; 
  
   for (int i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 

int S[2*N];

void test(){
   int n;
   cin >> n;
   vector<int> A(n);
   int ans = 0;
   f(i,0,n) cin >> A[i];
   vector<int> sq;
   int c = 0;
   int sm = maxSubArraySum(A,n);
   while(c*c<=sm){
      sq.pb(c*c);
      c++;
   }
   vector<int> pre(n+1);
   f(i,1,n+1){
      pre[i] = pre[i-1]+A[i-1];
   }
   f(i,1,n+1){
      for(auto &e : sq){
         if(e == pre[i]) ans++;
         ans += S[N+pre[i]-e];
      }
      S[N+pre[i]]++;
   }
   cout << ans << '\n';
   f(i,1,n+1){
      S[N+pre[i]]--;
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   f(i,1,tt+1){
      cout << "Case #" << i << ": ";
      test();
   }
   return 0;
}