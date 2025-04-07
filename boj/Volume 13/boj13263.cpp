#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
};

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<line> C;
	C.push_back({0, 0, -INF});
	ll ans{};
	for (int i = 0, j = 0; i < N; ++i) {
		while (j + 1 < C.size() && C[j + 1].c - EPS < A[i]) {
			++j;
		}
		ans = C[j].a * A[i] + C[j].b;
		line L{B[i], ans, -INF};
		while (C.size()) {
			L.c = get_x(L, C.back());
			if (L.c < C.back().c - EPS) {
				C.pop_back();
			} else {
				break;
			}
		}
		C.push_back(L);
	}
	cout << ans << "\n";
	return 0;
}
