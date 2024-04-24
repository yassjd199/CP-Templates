
	
//dont forget to call pre();


const int P = 127;
const int MOD = 1e9 + 7;
int pw[N];

void pre() {
    pw[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw[i] = (1LL * pw[i - 1] * P) % MOD;
    }
}

struct Hash {
    vector<int> pref;
    Hash(const string& s) {
        int hash_val = 0;
        pref.resize((int)s.size());
        for (int i = 0; i < s.size(); ++i) {
            hash_val = (1LL * hash_val * P) % MOD;
            hash_val = (hash_val + s[i]) % MOD;
            pref[i] = hash_val;
        }
    }

    int getHashValue(int l, int r) {
        int ret = pref[r];
        int sz = r - l + 1;
        --l;
        if (l >= 0) {
            ret -= (1LL * pref[l] * pw[sz]) % MOD;
            if (ret < 0) ret += MOD;
        }
        return ret;
    }
};
