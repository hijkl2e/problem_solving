#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

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
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.rbegin(), A.rend());
	for (int i = 1, j = 0; i < N; ++i) {
		while (i < N && (A[i].first == A[j].first || A[i].second <= A[j].second)) {
			A[i++].first = -1;
		}
		j = i;
	}
	sort(A.rbegin(), A.rend());
	while (A.back().first == -1) {
		A.pop_back();
	}
	A.push_back({0, 0});
	vector<line> B;
	B.push_back({A[0].first, 0, -INF});
	ll ans{};
	for (int i = 0, j = 0; i < A.size() - 1; ++i) {
		while (j + 1 < B.size() && B[j + 1].c - EPS < A[i].second) {
			++j;
		}
		ans = B[j].a * A[i].second + B[j].b;
		line L{A[i + 1].first, ans, -INF};
		while (B.size()) {
			L.c = get_x(L, B.back());
			if (L.c < B.back().c - EPS) {
				B.pop_back();
			} else {
				break;
			}
		}
		B.push_back(L);
	}
	cout << ans << "\n";
	return 0;
}
