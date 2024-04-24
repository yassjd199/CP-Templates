struct SegTree {
    vll st, lz;
    int n;
    ll netural_val = 0ll, lz_val = 0ll;
    SegTree(int n) {
        this->n = n;
        st.resize(4 * n, 0ll);
        lz.resize(4 * n, 0ll);
    }
    ll merg(ll l, ll r) {
        return l + r;
    }
    void push(int cur, int s, int e) {
        if (lz[cur] != lz_val) {
            st[cur] = lz[cur];
            if (s != e) {
                lz[2 * cur + 1] = lz[cur];
                lz[2 * cur + 2] = lz[cur];
            }
        }
        lz[cur] = lz_val;
    }
    void clear() {
        st.clear();
        st.resize(4 * n, 0ll);
        lz.clear(), lz.resize(4 * n, 0ll) ;
    }
    void build(int cur, int s, int e, vll &a) {
        if (s == e) {
            st[cur] = a[s];
            return ;
        }
        int m = (s + e) >> 1;
        build(2 * cur + 1, s, m, a);
        build(2 * cur + 2, m + 1, e, a);
        st[cur] = merg(st[2 * cur + 1], st[2 * cur + 2]);
    }
    void upd_rng(int l, int r, ll val, int cur, int s, int e) {
        push(cur, s, e);
        if (e < l || r < s) return ;
        if (s >= l && e <= r) {
            lz[cur] = val;
            push(cur, s, e);
            return ;
        }
        int m = s + ((e - s) >> 1);
        upd_rng(l, r, val, 2 * cur + 1, s, m);
        upd_rng(l, r, val, 2 * cur + 2, m + 1, e);
        st[cur] = merg(st[2 * cur + 1], st[2 * cur + 2]);

    }
    ll query(int l, int r, int cur, int s, int e) {
        push(cur, s, e);
        if (e < l || r < s) return netural_val;
        if (s >= l && e <= r) return st[cur];
        int m = (s + e) >> 1;
        return merg(query(l, r, 2 * cur + 1, s, m), query(l, r, 2 * cur + 2, m + 1, e));
    }
    void build(vll &a) {
        return build(0, 0, n - 1, a) ;
    }
    void upd(int pos, ll val) {
        return upd(pos, val, 0, 0, n - 1);
    }
    ll query(int l, int r) {
        return query(l, r, 0, 0, n - 1) ;
    }
    void upd_rng(int l, int r, ll val) {
        return upd_rng(l, r, val, 0, 0, n - 1);
    }

};
