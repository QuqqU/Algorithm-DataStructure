#include <iostream>
#include <algorithm>
using namespace std;

int arr[1005];

void quickSosrt(int l, int r) {
	if (l >= r) return;
	int pivot = arr[(l + r) / 2], low = l, high = r;
	while (low <= high) {
		while (arr[low] < pivot) low++;
		while (arr[high] > pivot) high--;
		if(low <= high) swap(arr[low++], arr[high--]);
	}
	quickSosrt(l, high);
	quickSosrt(low, r);
}


int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	quickSosrt(0, n - 1);
	for (int i = 0; i < n; i++)printf("%d\n", arr[i]);
	return 0;
}

