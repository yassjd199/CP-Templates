// 1-indexed BIT
ll fn[N];
void inc(int x, ll val) {
    for (; x < N; x += x & (-x)) fn[x] += val;
}
ll query(int x) {
    ll res = 0ll;
    for (; x; x -= x & (-x)) res += fn[x];
    return res ;
}
ll query(int l, int r) {
    return l == 0 ?  query(r) : query(r) - query(l - 1) ;
}
