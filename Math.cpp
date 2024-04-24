ll gcd(ll a, ll b) {
    return (b == 0) ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

ll mod_exp(ll b, ll p, ll m) {
    ll x = 1;
    while (p) {
        if (p & 1)
            x = (x * b) % m;
        b = (b * b) % m;
        p = p >> 1;
    }
    return x;
}

ll invFermat(ll a, ll p) {
    return mod_exp(a, p - 2, p);
}

ll exp(ll b, ll p) {
    ll x = 1;
    while (p) {
        if (p & 1)
            x = (x * b);
        b = (b * b);
        p = p >> 1;
    }
    return x;
}
