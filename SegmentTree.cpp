struct SegTree{
	vll st;
	int n;
	ll netural_val=0ll;
	SegTree(int n){
		this->n=n;
		st.resize(4*n,0ll);
	}
	ll merg(ll l,ll r){return l+r;}
	void clear(){st.clear();st.resize(4*n,0ll);}
	void build(int cur,int s,int e,vll &a){
		if(s==e){
			st[cur]=a[s];
			return ;
		}
		int m=(s+e)>>1;
		build(2*cur+1,s,m,a);
		build(2*cur+2,m+1,e,a);
		st[cur]=merg(st[2*cur+1],st[2*cur+2]);
	}
	void upd(int pos,ll val,int cur,int s,int e){
		if(s==e){
			st[cur]=val;
			return ;
		}
		int m=(s+e)>>1;
		(pos<=m) ? upd(pos,val,2*cur+1,s,m):upd(pos,val,2*cur+2,m+1,e);
		st[cur]=merg(st[2*cur+1],st[2*cur+2]);
		
	}
	ll query(int l,int r,int cur,int s,int e){
		if(e<l || r<s) return netural_val;
		if(s>=l && e<=r) return st[cur];
		int m=(s+e)>>1;
		return merg(query(l,r,2*cur+1,s,m),query(l,r,2*cur+2,m+1,e));
	}
	void build(vll &a) { return build(0,0,n-1,a) ;}
	void upd(int pos,ll val){ return upd(pos,val,0,0,n-1);}
	ll query(int l,int r){ return query(l,r,0,0,n-1) ;}
	
};
