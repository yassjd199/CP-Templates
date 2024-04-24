struct SparseTable {
    int n, m;
    vector<vll> sp;
    ll merg(ll l, ll r) {
        // change operation here ;
        return min(l, r);
    }
    SparseTable(int _n) {
        n = _n;
        m = (int)log2(n) + 2;
        sp.resize(n, vll(m));
    }
    void build(vll &v) {
        for (int i = 0; i < n; i++) sp[i][0] = v[i];
        for (int j = 1; j < m; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                sp[i][j] = merg(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
    }
    ll query(int l, int r) {
        int x = (int)log2(r - l + 1);
        return merg(sp[l][x], sp[r - (1 << x) + 1][x]);
    }
};
