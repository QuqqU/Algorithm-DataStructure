#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_SIZE 999
using namespace std;

void merge(int arr[], int l, int r) {
	int mid = (l + r) / 2, a = l, b = mid + 1, k = l;
	int buf[MAX_SIZE];
	while (a <= mid && b <= r) {
		if (arr[a] < arr[b]) buf[k++] = arr[a++];
		else buf[k++] = arr[b++];
	}
	while (a <= mid) buf[k++] = arr[a++];
	while (b <= r) buf[k++] = arr[b++];
	for (int i = l; i <= r; i++) arr[i] = buf[i];
}
void mergeSort(int arr[], int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, r);
}



int main() {
	int arr[1005];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)printf("%d\n", arr[i]);
	return 0;
}

