int to_int(string s){
   int ans = 0;
   for(char c : s) {
      ans = ans*10 + (c - '0');
   }
   return ans;
}