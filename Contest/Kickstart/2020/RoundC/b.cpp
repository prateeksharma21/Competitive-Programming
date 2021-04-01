#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#define ll long long
#define mod 1000000007
#define vi vector<int>
#define F(i,n) for(int i = 0; i < n; i++)
#define scan(n) scanf("%d",&n)
#define pi 3.14159265359
using namespace std;
ll power(ll a, ll b) {
   if (b == 0)return 1;
   ll res = 1;
   while (b) {
      if (b & 1)res = res * a % mod;
      a = a * a % mod;
      b >>= 1;
   }
   return res;
}
 
unsigned ll mulmod(unsigned ll a, unsigned ll b, unsigned ll m) {
   a = a % m;
   unsigned ll res = 0;
   while (b > 0) {
      if (b & 1)res = (res + a) % m;
      a = (a << 1) % m;
      b >>= 1;
   }
   return res;
}
 
unsigned ll power(unsigned ll a, unsigned ll b, unsigned ll m) {
   if (b == 0)return 1;
   unsigned ll res = 1;
   while (b) {
      if (b & 1)res = mulmod(res, a, m);
      a = mulmod(a, a, m);
      b >>= 1;
   }
   return res;
}
 
unsigned ll gcd(unsigned ll a, unsigned ll b) {
   if (a == 0)return b;
   return gcd(b%a, a);
}
 
bool millerTest(unsigned ll n, unsigned ll d) {
   unsigned ll a = 2 + rand() % (n - 4);
   unsigned ll x = power(a, d, n);
   if (x == 1 || x == n - 1)return true;
 
   while (d != n - 1) {
      x = mulmod(x, x, n);
      d <<= 1;
      if (x == 1)return false;
      if (x == n - 1)return true;
   }
   return false;
}
 
bool isPrime(unsigned ll n, int k) {
   if (n == 2 || n == 3)return true;
   if ((n & 1) == 0)return false;
   if (n <= 1)return false;
 
   unsigned ll d = n - 1;
   while ((d & 1) == 0)d >>= 1;
 
   F(i, k)if (!millerTest(n, d))return false;
   return true;
}
 
bool fermatTest(unsigned ll n, int k) {
   if (n < 2) return false;
   if (n < 4) return true;
 
   srand(time(0));
   unsigned ll a = rand() % (n - 2) + 2;
 
   while (k-- > 0) {
      if (power(a, n - 1, n) != 1) return false;
   }
 
   return true;
}
 
unsigned long long rhoFactor(unsigned long long n) {
   if (n < 2)
      return n;
 
   if (n % 2 == 0)
      return 2;
 
   srand(time(0));
 
   unsigned long long x = rand() % (n - 2) + 2;
   unsigned long long y = x;
   unsigned long long c = rand() % (n - 1) + 1;
 
   unsigned long long g = 1;
   while (g == 1) {
      y = (mulmod(y, 2, n) + c) % n;
      x = (mulmod(x, 2, n) + c) % n;
      x = (mulmod(x, 2, n) + c) % n;
      g = gcd(max(y, x) - min(y, x), n);
   }
 
   return g;
}
 
const int SIZE = 2e5 + 10;
ll arr[SIZE];
pair<ll, ll> tree[SIZE * 4];
 
void build(int a, int l, int r)
{
   if (l == r)
   {
      const ll idx = l + 1;
      tree[a] = {(idx % 2 == 1 ? 1 : -1) * idx * arr[l], (idx % 2 == 1 ? 1 : -1) * arr[l]};
   }
   else
   {
      int m = l + (r - l) / 2;
      build(a * 2, l, m);
      build(a * 2 + 1, m + 1, r);
      tree[a] = { tree[a * 2].first + tree[a * 2 + 1].first, tree[a * 2].second + tree[a * 2 + 1].second };
   }
}
 
void update(int a, int l, int r, int index, ll val)
{
   if (l > index || r < index)
      return;
 
   if (l == r)
   {
      arr[index] = val;
      const ll idx = l + 1;
      tree[a] = { (idx % 2 == 1 ? 1 : -1) * idx * arr[l], (idx % 2 == 1 ? 1 : -1) * arr[l] };
   }
   else
   {
      int m = l + (r - l) / 2;
      update(a * 2, l, m, index, val);
      update(a * 2 + 1, m + 1, r, index, val);
      tree[a] = { tree[a * 2].first + tree[a * 2 + 1].first, tree[a * 2].second + tree[a * 2 + 1].second };
   }
}
 
ll getAccumulativeSum(int a, int l, int r, int tl, int tr)
{
   if (l > tr || r < tl || l > r)
      return 0;
 
   if (tl <= l && r <= tr)
   {
      return tree[a].first;
   }
 
   int m = l + (r - l) / 2;
   return getAccumulativeSum(a * 2, l, m, tl, tr) + getAccumulativeSum(a * 2 + 1, m + 1, r, tl, tr);
}
 
ll getSum(int a, int l, int r, int tl, int tr)
{
   if (l > tr || r < tl || l > r)
      return 0;
 
   if (tl <= l && r <= tr)
   {
      return tree[a].second;
   }
 
   int m = l + (r - l) / 2;
   return getSum(a * 2, l, m, tl, tr) + getSum(a * 2 + 1, m + 1, r, tl, tr);
}
 
int main() {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   int t; cin >> t;
   for (int testCase = 1; testCase <= t; testCase++) {
      int n, q; cin >> n >> q;
      F(i, n) cin >> arr[i];
 
      build(1, 0, n - 1);
 
      ll result = 0;
 
      F(x, q)
      {
         string type; cin >> type;
         if (type == "U")
         {
            int idx, val; cin >> idx >> val;
            update(1, 0, n - 1, idx - 1, val);
         }
         else
         {
            int l, r; cin >> l >> r;
            ll allSum = getAccumulativeSum(1, 0, n - 1, 0, r - 1);
            if (l > 1) allSum -= getAccumulativeSum(1, 0, n - 1, 0, l - 2);
 
            allSum -= (l - 1) * getSum(1, 0, n - 1, l - 1, r - 1);
            if (l % 2 == 0) allSum *= -1;
            result += allSum;
         }
      }
      cout << "Case #" << testCase << ": " << result << endl;
   }
}