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
const int MOD = 1e9+7, N = 1e6 + 10; 

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void shift_solution(int & x, int & y, int a, int b, int cnt) {
    x += cnt * b;
    y -= cnt * a;
}

int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy) {
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return -1;
    a /= g;
    b /= g;

    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;

    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return -1;
    int lx1 = x;

    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;

    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return -1;
    int lx2 = x;

    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;

    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);

    if (lx > rx)
        return -1;
    return lx;
}

vector<int> pos[N];

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int n, m;
   long long k;
   cin >> n >> m >> k;
   vector<int> a(n), b(m);
   for (int &i : a) cin >> i;
   for (int &i : b) cin >> i;

   for (int i = 0; i < n; ++i) {
      pos[a[i]].push_back(i);
   }

   for (int i = 0; i < m; ++i) {
      pos[b[i]].push_back(i);
   }

   int gc = gcd(n, m);
   int lc = n * 1LL * m / gc;

   vector<int> D;

   for (int i = 1; i <= 2 * max(n, m); ++i) {
      if (pos[i].size() < 2) {
         continue;
      }
      int a = pos[i][0];
      int b = pos[i][1];
      if (abs(a - b) % gc) continue;
      int lx = find_all_solutions(n, -m, b - a, 0, N, 0, N);
      if (lx != -1) {
         D.push_back(lx * n + a + 1);
      }
   }

   sort(all(D));

   auto check = [&](int days) {
      int rem = days;
      for (int i : D) {
         int t = days - i;
         if (t < 0) break;
         rem -= t / lc;
         --rem;
         if (rem < k) return false;
      }
      return rem >= k;
   };

   int l = k, r = 1e18;
   int ans = 0;
   while (l <= r) {
      int m = (l + r) / 2;
      if (check(m)) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   assert(ans != 0);
   cout << ans << '\n';
   return 0;
}