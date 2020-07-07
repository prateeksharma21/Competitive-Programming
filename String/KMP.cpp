vector<int> prefix_fun(const string &s){
   int n = s.size();
   vector<int> PI(n);
   for(int i = 1; i < n; ++i){
      int j = PI[i-1];
      while(j and s[i] != s[j]){
         j = PI[j-1];
      }
      if(s[i] == s[j]) j++;
      PI[i] = j;
   }
   return PI;
}

vector<int> KMP(const string &s, const string &t){
   int n = s.size(), m = t.size();
   string r = t+"#"+s;
   vector<int> PI = prefix_fun(r);
   int l = r.length();
   vector<int> occ;
   for(int i = m+1; i < l; ++i){
      if(PI[i] == m){
         occ.push_back(i-2*m);
      }
   }
   return occ;
}