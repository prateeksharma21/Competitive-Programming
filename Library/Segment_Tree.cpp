template <typename T>
class SegTree{
public:
   vector<T> t,lazy;
   vector<T> A;
   int n;

   SegTree(int n){
      this->n = n;
      this->t.assign(4*n+10,0);
      this->lazy.assign(4*n+10,0);
   }

   SegTree(vector<T> a){
      this->n = a.size();
      this->A = a;
      this->t.assign(4*n,0);
      this->lazy.assign(4*n,0);
      build(1,0,n-1);
   }

   T fun(T a,T b){
      
   }

   void build(int v,int tl,int tr){
      if(tl == tr){
         t[v] = A[tl];
      }else{
         int tm = (tl+tr)/2;
         build(2*v,tl,tm);
         build(2*v+1,tm+1,tr);
         t[v] = fun(t[2*v],t[2*v+1]);
      }
   }

   void push(int v) {
      t[v*2] += lazy[v];
      lazy[v*2] += lazy[v];
      t[v*2+1] += lazy[v];
      lazy[v*2+1] += lazy[v];
      lazy[v] = 0;
   }

   void update(int v, int tl, int tr, int l, int r, T addend) {
      if (l > r) 
         return;
      if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
      } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = fun(t[v*2], t[v*2+1]);
      }
   }

   T query(int v, int tl, int tr, int l, int r) {
      if (l > r)
        return ; // Value
      if (l <= tl && tr <= r)
        return t[v];
      push(v);
      int tm = (tl + tr) / 2;
      return fun(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
   }

   void update(int l,int r,T val){
      update(1,0,n-1,l,r,val);
   }

   void update(int i,T val){
      update(i,i,val);
   }

   T query(int l,int r){
      return query(1,0,n-1,l,r);
   }

   T query(int i){
      return query(i,i);
   }
};