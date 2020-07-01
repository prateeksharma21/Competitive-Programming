vector<int> Rabin_Karp(string const &s, string const &t){
const int p = 29;
   const long long MOD = 10000000000129;
   int S = s.size(), T = t.size();
   if (S > T) return vector<int>();
   vector<long long> pw(T);
   pw[0] = 1;
   for (int i = 1; i < T; i++){
      pw[i] = pw[i - 1] * p % MOD;
   }
   vector<long long> H(T + 1);
   for (int i = 0; i < T; i++){
      H[i + 1] = (H[i] + (t[i] - 'a' + 1) * pw[i]) % MOD;
   }
   long long hs = 0;
   for (int i = 0; i < S; i++){
      hs = (hs + (s[i] - 'a' + 1) * pw[i]) % MOD;
   }
   vector<int> occurences;
   for (int i = 0; i + S - 1 < T; i++){
      long long cur_hs = (H[i + S] - H[i] + MOD) % MOD;
      if (cur_hs == (hs * pw[i]) % MOD){
         occurences.push_back(i);
      }
   }
   return occurences;
}
