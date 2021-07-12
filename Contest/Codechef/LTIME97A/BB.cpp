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
const int MOD = 1e9+7, N = 4e3 + 10;

int t[N][N];
int val[N][N];
int n, m, k;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = val[lx][ly];
        else
            t[vx][vy] = max(t[vx*2][vy], t[vx*2+1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = max(t[vx][vy*2], t[vx][vy*2+1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, m-1);
}

int sum_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return 0;
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return max(sum_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         , sum_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry));
}

int sum_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(vx, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return max(sum_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         , sum_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry));
}


void test(){
   cin >> n >> m >> k;
   vector<vector<int>> a(n + 1, vector<int>(m + 1));
   for (int i = 1; i <= n * m; ++i) {
      int x, y;
      cin >> x >> y;
      a[x - 1][y - 1] = (i & 1);
      val[x - 1][y - 1] = i;
   }
   build_x(1, 0, n - 1);
   vector<vector<int>> pre(n + 1, vector<int>(m + 1));
   for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
         pre[i][j] = a[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
      }
   }

   auto sum = [&](int x1, int y1, int x2, int y2) {
      return pre[x2][y2]+pre[x1-1][y1-1]-pre[x1-1][y2]-pre[x2][y1-1];
   };

   int alice = 1e18;
   int bob = 1e18;

   for (int i = 0; i + k - 1 < n; ++i) {
      for (int j = 0; j + k - 1 < m; ++j) {
         int val = sum(i + 1, j + 1, i + k, j + k);
         if (val == k * k) {
            alice = min(alice, sum_x(1, 0, n - 1, i, i + k - 1, j, j + k - 1));
         }
         if (val == 0) {
            bob = min(bob, sum_x(1, 0, n - 1, i, i + k - 1, j, j + k - 1));
         }
      }
   }
   debug(alice, bob);
   if (alice < bob) {
      cout << "Alice\n";
   } else if (alice > bob) {
      cout << "Bob\n";
   } else {
      cout << "Draw\n";
   }
   return;
}

int32_t main(){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tt = 1;
   cin >> tt;
   for (int t = 1; t <= tt; ++t) {
      test();
   }
   return 0;
}