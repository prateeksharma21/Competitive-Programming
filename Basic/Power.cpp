long long power(long long x,long long y){
   long long ans=1;
   x %= MOD;
   if(y < 0) return 0;
   if(y == 1) return ans;
   while(y){
      if(y & 1) ans = (ans*x) %MOD;
      x = x*x % MOD;
      y /= 2;
   }
   return ans;
}
 
long long inv(long long x){
   return power(x,MOD-2);
}