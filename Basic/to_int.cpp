int to_int(string s){
   int ans = 0,c = 1;
   reverse(all(s));
   for(auto &e : s){
      ans += (e-'0')*c;
      c *= 10;
   }
   return ans;
}