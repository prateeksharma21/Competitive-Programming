struct FenwickTree{
   int n;
   vector<ll> fenw;

   FenwickTree(int n){
      this->n = n;
      fenw.assign(n,0);
   }

   FenwickTree(vector<ll> a) : FenwickTree((int)a.size()){
      f(i,0,(int)a.size()){
         update(i,a[i]);
      }
   }

   ll sum(int r){
      ll res = 0;
      while(r>=0){
         res += fenw[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   ll sum(int l,int r){
      return sum(r)-sum(l-1);
   }

   void update(int ind,ll val){
      while(ind<n){
         fenw[ind] += val;
         ind = ind | (ind+1);
      }
   }
};