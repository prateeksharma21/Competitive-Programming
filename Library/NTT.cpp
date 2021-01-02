inline int add(int a, int b, int mod = MOD) {
  a += b; return a >= mod ? a - mod : a;
}
inline int sub(int a, int b, int mod = MOD) {
  a -= b; return a < 0 ? a + mod : a;
}
inline int mul(int a, int b, int mod = MOD) {
  return int((long long) a * b % mod);
}
inline int power(int base, long long ex, int mod = MOD) {
  int res = 1;
  for (; ex > 0; ex >>= 1) {
    if (ex & 1) res = mul(res, base, mod);
    base = mul(base, base, mod);
  }
  return res;
}
inline int inv(int a, int mod = MOD) {
  return power(a, mod - 2, mod);
}
inline int mdiv(int a, int b, int mod = MOD) {
  return mul(a, power(b, mod - 2,  mod));
}
inline void adds(int &a, int b, int mod = MOD) {
  a += b; if (a >= mod) a -= mod;
}
inline void subs(int &a, int b, int mod = MOD) {
  a -= b; if (a < 0) a += mod;
}
inline void muls(int &a, int b, int mod = MOD) {
  a = int((long long) a * b % mod);
}
inline void mdivs(int &a, int b, int mod = MOD) {
  a = mdiv(a, b, mod);
}
vector<int> fact,ifact;
void prep_fact(int mx = 1e6 + 40) {
  fact.assign(mx,0);
  ifact.assign(mx,0);
  fact[0] = 1;
  for (int i = 1; i < mx; ++i) fact[i] = mul(i, fact[i - 1]);
  ifact[mx - 1] = inv(fact[mx - 1]);
  for (int i = mx - 1; i > 0; --i) ifact[i - 1] = mul(i, ifact[i]);
}
inline int ncr(int n, int r) {
  if (n < r || r < 0 || n < 0) return 0;
  return mul(fact[n], mul(ifact[n - r], ifact[r]));
}

void ntt (vector<int> &A, bool invert, int x) {
   int n = A.size();
   int lg = log2(n);
   for (int i = 1; i < n; ++i) {
      int j = 0;
      for (int k = 0; k < lg; ++k) {
         if (i >> k & 1) {
            j |= (1 << (lg - k - 1));
         }
      }
      if (i < j) {
         swap(A[i], A[j]);
      }
   }
   if (invert) {
      x = inv(x);
   }
   for (int len = 2; len <= n; len <<= 1) {
      int wl = power(x, n / len);
      for (int i = 0; i < n; i += len) {
         int w = 1;
         for (int j = 0; j < len / 2; ++j) {
            int u = A[i + j], v = mul(w, A[i + j + len / 2]);
            A[i + j] = add(u, v);
            A[i + j + len / 2] = sub(u, v);
            muls(w, wl);
         }
      }
   }
   if (invert) {
      int invn = inv(n);
      for (int &x : A) {
         muls (x, invn);
      }
   }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
   int n = 1;
   while (n < a.size() + b.size()) {
      n <<= 1;
   }
   vector<int> fa(a.begin(), a.end());
   fa.resize(n);
   vector<int> fb(b.begin(), b.end());
   fb.resize(n);

   int primitive_root = 3; // check correct primitive root
   int x = power(primitive_root, (MOD - 1) / n);

   ntt(fa, false, x);
   ntt(fb, false, x);

   for (int i = 0; i < n; ++i) {
      muls(fa[i], fb[i]);
   }

   ntt(fa, true, x);
   return fa;
}