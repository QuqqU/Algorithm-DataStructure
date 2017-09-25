//boj 10254 highways 

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
const ll INF = 99999999999;

ii point[200005];

int ccw (ii a, ii b, ii c) {
	ll temp = (1LL * a.first * b.second + 1LL * b.first * c.second + 1LL * c.first * a.second) - (1LL * b.first * a.second + 1LL * c.first * b.second + 1LL * a.first * c.second);
	if (temp > 0) return 1;//ccw
	else if (temp < 0) return -1;//cw
	else return 0;//parallel
}

bool cmp(ii a, ii b) {
	int cp = ccw(point[0], a, b);
	if (cp == 0) return ((a.first - point[0].first) * (a.first - point[0].first) + (a.second - point[0].second) *(a.second - point[0].second)) < ((b.first - point[0].first) * (b.first - point[0].first) + (b.second - point[0].second) *(b.second - point[0].second)); 
	return cp == -1 ? 0 : 1;
}
const ii operator -(ii a) {
	return ii(-a.first, -a.second);
}
const ii operator -(ii a, ii b) {
	return ii(a.first - b.first, a.second - b.second);
}
ll sqdist (ii a, ii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
double distf(ii a){
    return sqrt(pow(a.first, 2.0) + pow(a.second, 2.0));
}
double angle(ii a, ii b){
    return acos((double)(a.first*b.first + a.second*b.second)*1.0/(distf(a)*1.0)/(distf(b)*1.0));
}

int main() {
	int testcase; scanf("%d", &testcase);
	while (testcase--) {

		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%lld %lld", &point[i].first, &point[i].second);
		swap(point[0], *min_element(point, point + n));
		sort(point + 1, point + n, cmp);

		stack<int> s;
		s.push(0); s.push(1);
		int next = 2;
		while (next < n) {
			while (s.size() >= 2) {
				int present = s.top();
				s.pop();
				int previous = s.top();
				if (ccw(point[previous], point[present], point[next]) > 0) {
					s.push(present);
					break;
				}
			}
			s.push(next++);
		}

		vector<ii> hull;
		int ssize = s.size();
		int p = ssize - 1; int q; ii aa(-INF, -INF);
		for(int i = 0; i < ssize; i++) {
			hull.push_back(point[s.top()]);
			s.pop();
			if (aa < hull[i]) {
				aa = hull[i];
				q = i;
			}
		}
		


		ii linevector(0, 1);
		ll ansdist = sqdist(hull[p], hull[q]);
		ii ans(p, q);

		int hsize = hull.size();
		for (int i = 0; i < hsize; i++) {
			double pdot = angle(linevector, hull[(p + 1) % hsize] - hull[p]);
			double qdot = angle(-linevector, hull[(q + 1) % hsize] - hull[q]);
			if (pdot <= qdot) {
				linevector = hull[(p + 1) % hsize] - hull[p];
				p = (p + 1) % hsize;
			}
			else {
				linevector = hull[q] - hull[(q + 1) % hsize];
				q = (q + 1) % hsize;
			}
			if (ansdist < sqdist(hull[p], hull[q])) {
				ansdist = sqdist(hull[p], hull[q]);
				ans = ii(p, q);
			}
		}

		printf("%lld %lld %lld %lld\n", hull[ans.first].first, hull[ans.first].second, hull[ans.second].first, hull[ans.second].second);
	}
	return 0;
}
