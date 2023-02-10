#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	int a{}, b{};
	double c{};
};

double get_x(ll a1, ll b1, ll a2, ll b2, ll K) {
	return (a2 * b1 - a1 * b2) * 1.0 / (K * (a2 + b2 - a1 - b1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<ii> A(N);
	for (auto &[d, n] : A) {
		cin >> n >> d;
		d += n;
	}
	sort(A.begin(), A.end());
	vector<line> B;
	for (auto &[d, n] : A) {
		if (B.size() && B.back().a + B.back().b == d) {
			continue;
		}
		double c = -INF;
		while (B.size()) {
			c = get_x(n, d - n, B.back().a, B.back().b, K);
			if (c < B.back().c - EPS) {
				B.pop_back();
			} else {
				break;
			}
		}
		B.push_back({n, d - n, c});
	}
	for (int i = 1, j = 0; i <= M; ++i) {
		while (j + 1 < B.size() && B[j + 1].c - EPS < i) {
			++j;
		}
		int d = B[j].a + K * i;
		int n = B[j].b - K * i;
		int g = gcd(d, n);
		d /= g, n /= g;
		cout << n << "/" << (n ? d : 0) << "\n";
	}
	return 0;
}
