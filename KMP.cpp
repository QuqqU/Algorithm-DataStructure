#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
using namespace std;


string s, w;
int fail[1000005];
vector<int> ans;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, s);
	getline(cin, w);

	int n = s.size(), m = w.size();
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && w[i] != w[j]) j = fail[j - 1];
		if (w[i] == w[j]) fail[i] = ++j;
	}

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && s[i] != w[j]) j = fail[j - 1];
		if (s[i] == w[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = fail[j];
			}
			else j++;
		}
	}

	printf("%lu\n", ans.size());
	for (int a : ans)
		printf("%d ", a + 1);
	puts("");
	return 0;
}
