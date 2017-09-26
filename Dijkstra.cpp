#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define IMP 999999999
using namespace std;
typedef pair<int, int> ii;

int v, e, start;
vector<ii> edge[20005];
vector<int> dist(20005, IMP);
priority_queue<ii, vector<ii>, greater<ii>> pq;// dist, v

int main() {
	scanf("%d %d %d", &v, &e, &start);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		edge[u].push_back(ii(w, v));
	}

	dist[start] = 0;
	pq.push(ii(dist[start], start));
	while (!pq.empty()) {
		int currdist = pq.top().first;
		int curr = pq.top().second;
		pq.pop();

		if (currdist > dist[curr]) continue;

		for (ii next : edge[curr]) {
			int nextdist = dist[curr] + next.first;
			if (dist[next.second] > nextdist) {
				dist[next.second] = nextdist;
				pq.push(ii(dist[next.second], next.second));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == IMP) printf("INF\n");
		else printf("%d\n", dist[i]);
	}



	return 0;
}
