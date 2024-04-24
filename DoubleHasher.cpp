
//dont forget to call pre( ) ;

const int P1 = 127;
const int P2 = 131;
const int mod1 = 1e9 + 7;
const int mod2 = 2e9 + 11;
int pw1[N], pw2[N];
void pre() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw1[i] = (1LL * pw1[i - 1] * P1) % mod1;
        pw2[i] = (1LL * pw2[i - 1] * P2) % mod2;
    }
}

struct Hash {
    vector<pair<int, int>> pref;
    Hash(const string& s) {
        int a = 0, b = 0;
        pref.resize((int)s.size());
        for (int i = 0; i < s.size(); ++i) {
            a = (1LL * a * P1) % mod1;
            b = (1LL * b * P2) % mod2;
            a = (a + s[i]) % mod1;
            b = (b + s[i]) % mod2;
            pref[i] = {a, b};
        }
    }

    pii getHashValue(int l, int r) {
        pii ret = pref[r] ;
        int sz = r - l + 1 ;
        --l;
        if (l >= 0) {
            ret.first -= (1LL * pref[l].first * pw1[sz]) % mod1;
            if (ret.first < 0) ret.first += mod1;
            ret.second -= (1LL * pref[l].second * pw2[sz]) % mod2;
            if (ret.second < 0) ret.second += mod2;
        }
        return ret;
    }
};
