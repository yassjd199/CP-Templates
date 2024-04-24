struct DSU {
    vector<ll> p, r;
    ll SetsCount;
    DSU(ll n) {
        p.resize(n + 1);
        r.resize(n + 1);
        for (int i = 0; i <= n; i++) p[i] = i, r[i] = 1;
        SetsCount = n;
    }
    ll find(ll e) {
        return e == p[e] ? e : p[e] = find(p[e]) ;
    }
    void merg(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return ;
        if (r[a] < r[b]) swap(a, b);
        SetsCount--;
        p[b] = a;
        r[a] += r[b];
        r[b] = 0ll;
    }
    bool same(ll a, ll b) {
        return find(a) == find(b) ;
    }
    ll rnk(ll x) {
        x = find(x);
        return r[x];
    }
    ll size() {
        return SetsCount ;
    }
};
