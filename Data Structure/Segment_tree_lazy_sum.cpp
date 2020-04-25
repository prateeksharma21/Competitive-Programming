int A[N];
int t[4*N];
int lazy[4*N];

void build(int v,int tl,int tr){
   if(tl == tr){
      t[v] = A[tl];
      return;
   }
   int tm = (tl+tr)/2;
   build(2*v,tl,tm);
   build(2*v+1,tm+1,tr);
   t[v] = t[2*v]+t[2*v+1];
}

void push(int v,int tl,int tr){
   if(lazy[v]){
      t[v] += (tr-tl+1)*lazy[v];
      if(tl!=tr){
         lazy[2*v] += lazy[v];
         lazy[2*v+1] += lazy[v];
      }
      lazy[v] = 0;
   }
}

void update(int v,int tl,int tr,int l,int r,int val){
   push(v,tl,tr);
   if(tl>r or tr<l) return;
   if(tl>=l and tr<=r){
      lazy[v] += val;
      push(v,tl,tr);
      return;
   }
   int tm = (tl+tr)/2;
   update(2*v,tl,tm,l,r,val);
   update(2*v+1,tm+1,tr,l,r,val);
   t[v] = t[2*v]+t[2*v+1];
}

int query(int v,int tl,int tr,int l,int r){
   if(tr<l or tl>r) return 0;
   push(v,tl,tr);
   if(tl>=l and tr<=r){
      return t[v];
   }
   int tm = (tl+tr)/2;
   return query(2*v,tl,tm,l,r)+query(2*v+1,tm+1,tr,l,r);
}