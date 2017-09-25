// boj 2188 축사배정

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 300
#define INF 2000000000
using namespace std;



class Edge {
public:
	int to, capacity, flow;
	Edge* reverse;

	Edge() : Edge(-1, 0) {}
	Edge(int t, int c) : to(t), capacity(c), flow(0), reverse(nullptr) {}

	int spare() {
		return capacity - flow;
	}
	void addFlow(int amt) {
		flow += amt;
		reverse->flow -= amt;
	}
};

vector<Edge*> edge[MAX_N * 3];
void addEdge(int a, int b, int capacity) {
	Edge* ab = new Edge(b, capacity);
	Edge* ba = new Edge(a, 0);
	ab->reverse = ba;
	ba->reverse = ab;
	edge[a].push_back(ab);
	edge[b].push_back(ba);
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int source = 0, sink = MAX_N * 2;
	for (int i = 1; i <= m; i++) {
		addEdge(source, i, 1);
		addEdge(i + MAX_N, sink, 1);
	}
	for (int i = 1; i <= m; i++) {
		int s; scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			int buf;  scanf("%d", &buf);
			addEdge(i, buf + MAX_N, 1);
		}
	}

	int totalflow = 0;
	while (1) {
		vector<int> parent(MAX_N * 3, -1);
		Edge* path[MAX_N * 3] = { 0 };
		queue<int> q;

		q.push(source);
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (Edge* e : edge[curr]) {
				int next = e->to;
				if (e->spare() > 0 && parent[next] == -1) {
					q.push(next);
					parent[next] = curr;
					path[next] = e;
					if (next == sink) break;
				}
			}
		}
		
		if (parent[sink] == -1) break;

		int amt = INF;
		for (int i = sink; i != source; i = parent[i])
			amt = min(amt, path[i]->spare());
		for (int i = sink; i != source; i = parent[i])
			path[i]->addFlow(amt);
		
		totalflow += amt;
	}

	printf("%d\n", totalflow);
	for (int i = 0; i < MAX_N * 3; i++)
		for (auto& cursor : edge[i])
			delete cursor;
	return 0;
}
