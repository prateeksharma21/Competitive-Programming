template<class T>
struct Fenwick{
   int n;
   vector<T> bit;

   Fenwick(int n){
      this->n = n;
      bit.assign(n,0);
   }

   Fenwick(vector<T> a) : Fenwick((int)a.size()){
      for(int i = 0; i < int(a.size()); ++i){
         update(i,a[i]);
      }
   }

   T query(int r){
      T res = 0;
      while(r>=0){
         res += bit[r];
         r = r&(r+1);
         r--;
      }
      return res;
   }

   T query(int l,int r){
      return query(r)-query(l-1);
   }

   void update(int i,T val){
      while(i < n){
         bit[i] += val;
         i = i | (i+1);
      }
   }

   void range_add(int l,int r,T val){
      update(l,val);
      update(r+1,-val);
   }
};