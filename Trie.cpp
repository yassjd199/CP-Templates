struct node {
    int nxt[26];
    int end;
    int pref;
    node() {
        memset(nxt, 0, sizeof(nxt));
        end = pref = 0;
    }
};

struct Trie {

    vector<node> T;

    Trie() {
        T.resize(1);
    }

    void insert(string &word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) {
                T[cur].nxt[x] = T.size();
                T.emplace_back();
            }

            cur = T[cur].nxt[x];
            T[cur].pref++;
        }
        T[cur].end++;
    }

    int countWordsEqualTo(string &word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return  0;
            cur = T[cur].nxt[x];
        }
        return T[cur].end;
    }

    int countWordsStartingWith(string &word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return  0;
            cur = T[cur].nxt[x];
        }
        return T[cur].pref;
    }

    void erase(string &word) {
        int cur = 0;
        for (auto c : word) {
            int x = c - 'a';
            if (!T[cur].nxt[x]) return  ;
            cur = T[cur].nxt[x];
            T[cur].pref--;
        }
        T[cur].end--;

    }
    void dfs(int nd, int d) {
        int i;
        for (i = 0; i < 26; i++) {
            if (T[nd].nxt[i]) {
                if (T[nd].pref != 1 && T[T[nd].nxt[i]].pref == 1)
                    // some logic  
                    dfs(T[nd].nxt[i], d + 1);
            }
        }
    }
};
