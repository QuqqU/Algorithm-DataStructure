#include <iostream>
#include <algorithm>
using namespace std;

int heap[1005];

void heapSort(int n) {
	int sv = n;
	while (sv > 0) {
		swap(heap[1], heap[sv--]);
		int curr = 1;
		while (1) {
			int l = curr * 2, r = curr * 2 + 1, c = curr;
			if (l <= sv && heap[c] < heap[l]) c = l;
			if (r <= sv && heap[c] < heap[r]) c = r;
			if (c == curr) break;
			swap(heap[curr], heap[c]);
			curr = c;
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &heap[i]);
		int a = i;
		while (a > 1) {
			if (heap[a / 2] < heap[a])
				swap(heap[a / 2], heap[a]);
			a /= 2;
		}
	}
	heapSort(n);
	for (int i = 1; i <= n; i++) printf("%d\n", heap[i]);
	return 0;
}
