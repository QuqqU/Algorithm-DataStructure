#include <bits/stdc++.h>
#define FASTIO  \
    cin.tie(0); \
    ios::sync_with_stdio(false);
using namespace std;
using ll = long long int;
using ii = pair<int, int>;

namespace CHT {

const int MAX_LINES = 1e6 + 5;
const double INIT_X = -1e10;

// y = ax + b
struct Line {
    ll a, b;
    double s;  // starting x-point (from s)

    Line(ll a, ll b) : a(a), b(b), s(INIT_X) {}

    ll f(ll x) {
        return a * x + b;
    }
};
vector<Line> poly;  // polygon shell

inline double cross_point(Line& l, Line& r) {
    return (double)(r.b - l.b) / (l.a - r.a);
}

void add_line(ll a, ll b) {
    auto line = Line(a, b);
    while (!poly.empty()) {
        auto& top = poly.back();
        line.s = cross_point(line, top);
        if (top.s <= line.s)
            break;
        else
            poly.pop_back();
    }
    poly.push_back(std::move(line));
}

ll calc(ll x) {
    int l = 0, r = poly.size();
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (poly[m].s <= x)
            l = m;
        else
            r = m;
    }

    return poly[l].f(x);
}

}  // namespace CHT
using namespace CHT;

ll a, b, c;
ll psum[MAX_LINES];
ll dp[MAX_LINES];

// dp := max(Ax + B) + D
ll A(int j) {
    return -2 * a * psum[j];
}
ll B(int j) {
    return a * psum[j] * psum[j] - b * psum[j] + dp[j];
}
ll D(int i) {
    return a * psum[i] * psum[i] + b * psum[i] + c;
}

int main() {
    FASTIO;

    int n;
    cin >> n;

    cin >> a >> b >> c;
    for (int i = 1; i <= n; i++) {
        cin >> psum[i];
        psum[i] += psum[i - 1];
    }

    dp[1] = D(1);
    add_line(A(1), B(1));
    for (int i = 2; i <= n; i++) {
        ll x = psum[i];
        dp[i] = max(D(i), calc(x) + D(i));
        add_line(A(i), B(i));
    }

    cout << dp[n] << endl;

    return 0;
}
