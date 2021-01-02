void fft (vector<cd> &A, bool invert) {
   int n = A.size();
   int lg = log2(n);
   for (int i = 0; i < n; ++i) {
      int j = 0;
      for (int k = 0; k < lg; ++k) {
         if (i >> k & 1) j |= (1 << (lg - k - 1));
      }
      if (i < j) swap(A[i], A[j]);
   }
   for (int len = 2; len <= n; len <<= 1) {
      double angle = 2 * PI / len;
      if (invert) angle *= -1;
      cd wl(cos(angle), sin(angle));
      for (int i = 0; i < n; i += len) {
         cd w(1);
         for (int j = 0; j < len / 2; ++j) {
            cd u = A[i + j], v = w * A[i + j + len / 2];
            A[i + j] = u + v;
            A[i + j + len / 2] = u - v;
            w *= wl;
         }
      } 
   }
   if (invert) {
      for (auto &x : A) {
         x /= n;
      }
   }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b) {
   vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
   int n = 1;
   while (n < a.size() + b.size()) {
      n <<= 1;
   }
   fa.resize(n);
   fb.resize(n);
   fft(fa, false);
   fft(fb, false);
   for (int i = 0; i < n; ++i) {
      fa[i] *= fb[i];
   }
   fft(fa, true);
   vector<int> res(n);
   for (int i = 0; i < n; ++i) {
      res[i] = round(fa[i].real());
   }
   return res;
}