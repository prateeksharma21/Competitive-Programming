pair<vector<int>,vector<int>> Manacher(const string & s){
   int n = s.length();
   vector<int> Odd(n);
   int l = 0, r = -1;
   for(int i = 0; i < n; ++i){
      Odd[i] = 1;
      if(i <= r){
         Odd[i] = min(Odd[r-i+l],r-i+1);
      }
      while(i-Odd[i] >= 0 and i+Odd[i] < n and s[i-Odd[i]] == s[i+Odd[i]]){
         ++Odd[i];
      }
      if(i+Odd[i]-1 > r){
         l = i-Odd[i]+1;
         r = i+Odd[i]-1;
      }
   }
   vector<int> Even(n);
   l = 0, r = -1;
   for(int i = 0; i < n; ++i){
      if(i <= r){
         Even[i] = min(Even[r-i+l+1],r-i+1);
      }
      while(i-Even[i]-1 >= 0 and i+Even[i] < n and s[i-Even[i]-1] == s[i+Even[i]]){
         ++Even[i];
      }
      if(i+Even[i]-1 > r){
         l = i-Even[i];
         r = i+Even[i]-1;
      }
   }
   return {Odd,Even};
}
