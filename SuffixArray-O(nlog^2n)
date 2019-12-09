int sa[MAX], lcp[MAX], g[MAX], tg[MAX];


void f(const string& s) {
    int n = s.size();
    if(n == 1) return;
    
    
    for(int i = 0; i < n; i++) sa[i] = i, g[i] = s[i];
    g[n] = -1;
    
    for(int t = 1; t < n; t <<= 1) {
        auto cmp = [&](int i, int j) {
            if(g[i] == g[j]) return g[i + t] < g[j + t];
            return g[i] < g[j];
        };
        sort(sa, sa + n, cmp);
        
        tg[sa[0]] = 0;
        for(int i = 1; i < n; i++) tg[sa[i]] = tg[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        
        for(int i = 0; i < n; i++) g[i] = tg[i];
    }
    
    for(int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
        if(g[i] == n - 1) continue;
        int j = sa[g[i] + 1];
        while(s[i + k] == s[j + k]) k++;
        
        lcp[g[i]] = k;
    }
}
