

typedef long long int ll;
ll tree[100005];


int sum(int i) {//from index 1 to index i, sum
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
void update(int i, int dif) {
    while (i <= n) {
        tree[i] += dif;
        i += (i & -i);
    }
}
