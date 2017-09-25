class Unionfind {
public:
	int comp, SZ;//number of components, max size of components
	vector<int> parent, rank, size;

	Unionfind(int n) : comp(n), SZ(1), parent(n), rank(n, 1), size(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int me) {
		if (me == parent[me]) return me;
		return parent[me] = find(parent[me]);
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		if (rank[a] > rank[b]) swap(a, b);
		parent[a] = b;
		if(rank[a] == rank[b]) rank[b]++;
		comp--;
		size[b] += size[a];
		SZ = max(SZ, size[b]);
	}

	int getsize(int a) {
		return size[find(a)];
	}
};

