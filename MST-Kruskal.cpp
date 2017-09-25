#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> intii;
priority_queue<intii, vector<intii>, greater<intii>> pq;

class UnionFind {
public:
	vector<int> parent, rank;
	UnionFind(int n) : parent(n + 1), rank(n + 1, 1) {
		for (int i = 1; i <= n; i++) parent[i] = i;
	}

	int find(int me) {
		if (me == parent[me]) return me;
		return parent[me] = find(parent[me]);
	}
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return false;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		if (rank[a] == rank[b]) rank[b]++;
		return true;
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);//n - number of vertexes, m - number of edges
	UnionFind uf(n);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);//from a to b, edge cost is c
		pq.push(intii(c, ii(a, b)));
	}
	int ans = 0;
	while (!pq.empty()) {
		int weight = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if(uf.merge(a, b)) ans += weight;
	}
	printf("%d\n", ans);
	return 0;
}
