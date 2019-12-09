const int MAX = 500'005;


int sa[MAX], lcp[MAX], g[MAX], gg[MAX], tg[MAX], cnt[MAX];


void f(const string& s) {
    int n = s.size();
    if(n == 1) return;
    
    int lim = max(256, n);
    for(int i = 0; i < n; i++) sa[i] = i, g[i] = s[i];


    
    for(int t = 1; t < n; t <<= 1) {
        for(int i = 0; i <= lim; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++) cnt[g[min(i + t, n)]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) gg[--cnt[g[min(i + t, n)]]] = i;
        
        for(int i = 0; i <= lim; i++) cnt[i] = 0;
        for(int i = 0; i < n; i++) cnt[g[i]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[g[gg[i]]]] = gg[i];
        
        
        
        auto cmp = [&](int i, int j) {
            if(g[i] == g[j]) return g[i + t] < g[j + t];
            return g[i] < g[j];
        };
        
        tg[sa[0]] = 1;
        for(int i = 1; i < n; i++) tg[sa[i]] = tg[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        for(int i = 0; i < n; i++) g[i] = tg[i];
    }
    
    
    for(int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
        if(g[i] - 1 == n - 1) continue;
        int j = sa[(g[i] - 1) + 1];
        while(s[i + k] == s[j + k]) k++;
        
        lcp[g[i] - 1] = k;
    }
    
    
}


///////////////////////////////////////////////////




void f(const string& s) {
    int n = s.size();
    if(n == 1) return;
    
    int lim = max(26, n);
    for(int i = 0; i < n; i++) sa[i] = i, g[i] = s[i] - 'a' + 1;
    
    for(int t = 1; t < n; t <<= 1) {
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) cnt[g[min(i + t, n)]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) gg[--cnt[g[min(i + t, n)]]] = i;
    
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) cnt[g[i]]++;
        for(int i = 1; i <= lim; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[g[gg[i]]]] = gg[i];

        auto cmp = [&](int i, int j) {
            if(g[i] == g[j]) return g[i + t] < g[j + t];
            return g[i] < g[j];
        };
        
        tg[sa[0]] = 1;
        for(int i = 1; i < n; i++) tg[sa[i]] = tg[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        
        memcpy(g, tg, sizeof(g));
    }
    
    for(int i = 0, k = 0; i < n; i++, k = max(k - 1, 0)) {
        if(g[i] - 1 == n - 1) continue;
        int j = sa[(g[i] - 1) + 1];
        while(s[i + k] == s[j + k]) k++;
        
        lcp[g[i] - 1] = k;
    }
}
