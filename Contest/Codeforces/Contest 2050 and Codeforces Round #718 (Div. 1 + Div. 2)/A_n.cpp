#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<map>
#include<iterator>
#include <unordered_map>
#include <unordered_set>
#define ll              long long
#define lli             long long int
#define pb              push_back
#define mp              make_pair
#define f(i,a,b)        for (int i = a; i<=b; i++)
#define fr(i,a,b)       for (int i = a; i>=b; i--)
#define RIP(i,n)        for(int i=0; i<n; i++)
#define F(i,a,b)        for(int i=a; i<b; i++)
#define sz(x)           (int)(x).size()
#define nl              '\n'
#define Max             100000
#define mod             1e9+7
using namespace std;
void urmi()
{
    ll n1,i=2050,c=0,d=INT_MAX;
        cin>>n1;
        for(i=2050;i<=n1;i*=10){
            if(n1%i==0) d=min(d,n1/i);
        }
        i/=10;
        while(n1){
            if(i<2050||n1<2050||n1==0) break;
            if(n1%i==0){
                c+=n1/i;
                d=min(d,c);
                break;
            }
            if(n1<i){
                i/=10;continue;
            }
            c+=n1/i;
            n1-=(n1/i)*i;
            if(n1<i) i/=10;
            if(i<2050||n1<2050||n1==0) break;
        }
        if(d!=INT_MAX){
            cout<<d<<endl;
        }
        else cout<<"-1"<<endl;
        return;
}
int main()
{
    int t;
    cin >> t;
    //t = 1;
    while(t--)
    {
        urmi();
    }
}