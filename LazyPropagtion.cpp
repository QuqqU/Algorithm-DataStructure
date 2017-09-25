#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

struct Tree {
	ll value, lazy;
};
ll arr[1000005];
Tree tree[4000005];

void propagate (int n, int nl, int nr) {
	if (tree[n].lazy != 0) {
		tree[n].value += (nr - nl + 1) * tree[n].lazy;
		if (nl != nr) {
			tree[n * 2].lazy += tree[n].lazy;
			tree[n * 2 + 1].lazy += tree[n].lazy;
		}
		tree[n].lazy = 0;
	}
}
ll update (int l, int r, ll nv, int n, int nl, int nr) {
	propagate(n, nl, nr);
	if (r < nl || nr < l) return tree[n].value;
	if (l <= nl && nr <= r) {
		if (nl != nr) {
			tree[n * 2].lazy += nv;
			tree[n * 2 + 1].lazy += nv;
		}
		return tree[n].value += (nr - nl + 1) * nv;
	}
	return tree[n].value = update(l, r, nv, n * 2, nl, (nl + nr) / 2) + update(l, r, nv, n * 2 + 1, (nl + nr) / 2 + 1, nr);
}
ll query (int l, int r, int n, int nl, int nr) {
	propagate(n, nl, nr);
	if (r < nl || nr < l) return 0;
	if (l <= nl && nr <= r) return tree[n].value;
	return query(l, r, n * 2, nl, (nl + nr) / 2) + query(l, r, n * 2 + 1, (nl + nr) / 2 + 1, nr);
}
ll init (int n, int nl, int nr) {
	if (nl == nr) return tree[n].value = arr[nl];
	return tree[n].value = init(n * 2, nl, (nl + nr) / 2) + init(n * 2 + 1, (nl + nr) / 2 + 1, nr);
}



int main(){

	/*
	source edit
	*/

	return 0;
}
