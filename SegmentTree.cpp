#include <iostream>
#include <algorithm>
using namespace std;
int arr[100005];
long long int tree[400005];
long long int update (int idx, int newValue, int node, int nl, int nr) {
	if (idx < nl || nr < idx) return tree[node];
	if (nl == nr) return tree[node] = newValue;
	return tree[node] = update(idx, newValue, node * 2, nl, (nl + nr) / 2) + update(idx, newValue, node * 2 + 1, (nl + nr) / 2 + 1, nr);
}
long long int query (int l, int r, int node, int nl, int nr) {
	if (r < nl || nr < l) return 0;
	if (l <= nl && nr <= r) return tree[node];
	return query(l, r, node * 2, nl, (nl + nr) / 2) + query(l, r, node * 2 + 1, (nl + nr) / 2 + 1, nr);
}
long long int init (int node, int nl, int nr) {
	if (nl == nr) return tree[node] = arr[nl];
	return tree[node] = init(node * 2, nl, (nl + nr) / 2) + init(node * 2 + 1, (nl + nr) / 2 + 1, nr);
}

int main () {
	int n, q; scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	init(1, 1, n);
	for (int i = 0; i < q; i++) {
		int x, y, a, b; scanf("%d %d %d %d", &x, &y, &a, &b);
		if (x > y) swap(x, y);
		printf("%lld\n", query(x, y, 1, 1, n));
		update(a, b, 1, 1, n);
	}
	return 0;
}
