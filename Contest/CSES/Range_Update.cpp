/*
  Vishal Shrivastava
  i_am_kirito
*/
#include <bits/stdc++.h>
using namespace std;
#define minpq priority_queue <int, vector<int>, greater<int> >
#define maxpq  priority_queue <int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
const int mod = 1e9+7, N = 8e5 + 10;
int n,q,a[N],st[N],lazy[N]={0};
int sumrec(int l,int r,int lo,int hi,int p)
{ 
  if(lazy[p]!=0)
  {
    st[p]=st[p]+(hi-lo+1)*lazy[p];
    if(lo!=hi)
    {
      lazy[2*p+1]+=lazy[p];
      lazy[2*p+2]+=lazy[p];
    }
    lazy[p]=0;
  }
  if(l>hi||r<lo||lo>hi)
  return 0;
  if(l<=lo&&r>=hi)
  {
  
    return st[p];
  }
  int mid=(lo+hi)/2;
  return sumrec(l,r,lo,mid,2*p+1)+sumrec(l,r,mid+1,hi,2*p+2); 
 
}
int sum(int l,int r)
{
  return sumrec(l,r,0,n-1,0);
}
int updaterec(int l,int r,int diff,int lo,int hi,int p)
{
  if(lazy[p]!=0)
  {
    st[p]=st[p]+(hi-lo+1)*lazy[p];
    if(lo!=hi)
    {
      lazy[2*p+1]+=lazy[p];
      lazy[2*p+2]+=lazy[p];
    }
    lazy[p]=0;
  }
  if(l>hi||r<lo||lo>hi)
  {  
    return st[p];
  }
  if(l<=lo&&r>=hi)
  {
    st[p]=st[p]+(hi-lo+1)*diff;
    if(lo!=hi)
    {
      lazy[2*p+1]+=diff;
      lazy[2*p+2]+=diff;
    }
    return st[p];
  }
  int mid=(lo+hi)/2;
  st[p]=updaterec(l,r,diff,lo,mid,2*p+1)+updaterec(l,r,diff,mid+1,hi,2*p+2);
  return st[p];
}
void update(int l,int r,int diff)
{
  updaterec(l,r,diff,0,n-1,0);
}
int constructrec(int lo,int hi,int p)
{
  if(lo==hi)
  {
    st[p]=a[lo];
    return a[lo];
    
  }
  int mid=(lo+hi)/2;
    st[p]=constructrec(lo,mid,2*p+1)+constructrec(mid+1,hi,2*p+2);
    return st[p];
}
void construct()
{
  constructrec(0,n-1,0);
}
void solve()
{
   cin>>n>>q;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   construct();
   while(q--)
   {
    int in;
    cin>>in;
    //update from l to r inclusive
    if(in==1)
    {
      int l,r,ele;
      cin>>l>>r>>ele;
      l--,r--;
      update(l,r,ele);
    }
    else
    { //value at a point
      int k;
      cin>>k;
      k--;
      cout<<sum(k,k)<<"\n";
    }
   }
  return;
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
}