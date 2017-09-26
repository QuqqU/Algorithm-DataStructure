#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[1005];
queue<int> q;

vector<bool> visited(1005, false);
vector<bool> discovered(1005, false);

void dfs (int curr) {
	visited[curr] = true;
	printf("%d ", curr);
	for (int next : edge[curr])
		if (!visited[next]) dfs(next);
}
void bfs(int start){
   	q.push(start);
	discovered[start] = true;
	while (!q.empty()) {
		int curr = q.front();
		printf("%d ", curr);
		q.pop();
		for (int next : edge[curr])
			if (!discovered[next]) {
				discovered[next] = true;
				q.push(next);
			}
	} 
}


int main () {
	int n, m, v; scanf("%d %d %d", &n, &m, &v);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		edge[a].push_back(b); edge[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(edge[i].begin(), edge[i].end());

	dfs(v); puts("");
    bfs(v); puts("");

	return 0;
}
