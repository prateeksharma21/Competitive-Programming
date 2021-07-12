#ifdef Prateek
  #include "Prateek.h"
#else
  #include <bits/stdc++.h>
  using namespace std;
  #define debug(...) 42
#endif
#define int ll
#define all(c) begin(c),end(c)
using ll = long long;
const int MOD = 1e9+7, N = 1e5 + 10; 

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int getRand(int l, int r){
   uniform_int_distribution<int> uid(l, r);
   return uid(rng);
}

// https://github.com/galencolin/cp-templates/blob/master/templates/string_hash.cpp
int kk[5] = {
  89, 
  101, 
  189,
  94,
  621
};

int primes[5] = {
  533000401,
  735632791,
  776531419,
  797003413,
  1062599999,
};

struct string_hash {
  int len;
  ll mod, poly, inv;
  vector<ll> prefix;
  vector<ll> invs;
  
  void init(int n, string s, ll k = 89, ll m = 1000000007) {
    mod = m;
    poly = k;
    prefix = vector<ll>(n);
    invs = vector<ll>(n);

    invs[0] = 1;
    inv = minv(k);
    for (int i = 1; i < n; i++) {
      invs[i] = (invs[i - 1] * inv) % mod;
    }

    ll x = 1;
    prefix[0] = (s[0] - '0' + 1);
    for (int i = 1; i < n; i++) {
      x = (x * k) % mod;
      prefix[i] = (prefix[i - 1] + x * (s[i] - '0' + 1)) % mod;
    }

    len = n;
  }

  void extend(string next) {
    int x = next.length();
    for (int i = 0; i < x; i++) {
      invs.push_back((invs[i + len - 1] * inv) % mod);
    }

    ll p = mpow(poly, len - 1);
    for (int i = 0; i < x; i++) {
      p = (p * poly) % mod;
      prefix.push_back((prefix[i + len - 1] + p * (next[i] - '0' + 1)) % mod);
    }

    len += x;
  }
  
  void kill(int sz) { // remove last [sz] characters
     for (int i = 0; i < sz; i++) {
        invs.pop_back();
        prefix.pop_back();
     }
     
     len -= sz;
  }

  ll get_hash(int left, int right) {
    if (left == 0) return prefix[right];
    return ((prefix[right] - prefix[left - 1] + mod) * invs[left]) % mod;
  }

  ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
      if (exp % 2 == 1) {
          res = (res * base) % mod;
      }
      exp >>= 1;
      base = (base * base) % mod;
    }
    return res;
  }
  ll minv(ll base) {
    return mpow(base, mod - 2);
  }
};

template<int K>
struct multihash {
  string_hash sh[K];

  void init(int n, string s) {
    for (int i = 0; i < K; i++) {
      sh[i].init(n, s, kk[4 - i], primes[4 - i]);
    }
  }
  
  void extend(string s) {
     for (int i = 0; i < K; i++) {
      sh[i].extend(s);
     }
  }
  
  void kill(int x) {
     for (int i = 0; i < K; i++) {
      sh[i].kill(x);
     }
  }

  int get_hash(int l, int r, int x, int y) {
    for (int i = 0; i < K; i++) {
      int b = sh[i].get_hash(x, y);
      int a = sh[i].get_hash(l, r);
      if (a != b) return 0;
    }
    return 1;
  }

  bool compare(vector<ll> a, vector<ll> b) {
    for (int i = 0; i < K; i++) {
      if (a[i] != b[i]) return 0;
    }
    return 1;
  }
};

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   multihash<5> H;
   H.init(n, s);
   string res = "";
   for (int i = 0; i < n; ++i) {
      int l = 1, r = min(n - 1 - i, i + 1);
      int lst = min(i + i + 1, n - 1);
      int eq = -1;
      while (l <= r) {
         int m = (l + r) / 2;
         int c = H.get_hash(0, m - 1, i + 1, i + 1 + m - 1);
         if (c) {
            eq = m;
            l = m + 1;
         } else {
            r = m - 1;
         }
      }
      if (eq == -1) {
         if (i == n - 1) {
            res = s;
            break;
         }
         assert(s[i + 1] != s[0]);
         if (s[i + 1] > s[0]) {
            res = s.substr(0, i + 1);
            break;
         }
      } else {
         if (i + eq == lst) {
            continue;            
         }
         if (s[i + eq + 1] > s[eq]) {
            res = s.substr(0, i + 1);
            break;
         }
      }
   }
   int sz = res.size();
   for (int i = 0; i < k; ++i) {
      cout << res[i % sz];
   }
   cout << '\n';
   return 0;
}