class LCA { // base 0
public:
	const int expMax = 21;

	int n;
	vector<vector<int>> parent, edge;
	vector<int> depth;

	LCA(int N) : n(N) {
		parent.assign(n, vector<int>(expMax, -1));
		edge.resize(n);
		depth.assign(n, -1);
	}

	void make() {
		depth[0] = 0;
		dfs(0);
		
		for(int j = 0; j < expMax - 1; j++)
			for(int i = 1; i < n; i++)
				if(parent[i][j] != -1) 
					parent[i][j + 1] = parent[parent[i][j]][j];
	}

	void dfs(int curr) {
		for(int next : edge[curr]) 
			if(depth[next] == -1) {
				depth[next] = depth[curr] + 1;
				parent[next][0] = curr;
				dfs(next);
			}
	}

	int query(int a, int b) {
		if(depth[a] < depth[b]) swap(a, b);
		int dif = depth[a] - depth[b];

		int j = 0;
		while(dif) {
			if(dif & 1) a = parent[a][j];
			dif >>= 1;
			j++;
		}
		
		if(a != b) {
			for(int j = expMax - 1; j >= 0; j--) 
				if(parent[a][j] != -1 && parent[a][j] != parent[b][j]) {
					a = parent[a][j];
					b = parent[b][j];
				}
			a = parent[a][0];
		}
		
		return a;
	}
};
