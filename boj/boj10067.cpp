#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const double EPS = 1e-9;

struct line {
	ll a{}, b{};
	double c{};
	int d{};
};

double get_x(line &l1, line &l2) {
	return (l1.b - l2.b) * 1.0 / (l2.a - l1.a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	vector<ll> dp(N);
	vector<vector<int>> par(K, vector<int>(N, -1));
	vector<line> B;
	B.push_back({0, 0, -INF, 0});
	for (int k = 0; k < K; ++k) {
		vector<line> C;
		for (int i = k, j = 0; i < N - 1; ++i) {
			while (j + 1 < B.size() && B[j + 1].c - EPS < A[i] && B[j + 1].d < i) {
				++j;
			}
			dp[i] = B[j].a * A[i] + B[j].b + (A[N - 1] - A[i]) * A[i];
			par[k][i] = B[j].d;
			line L{A[i], dp[i] - A[N - 1] * A[i], -INF, i};
			if (C.size() && C.back().a == L.a) {
				continue;
			}
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
		swap(B, C);
	}
	int x = max_element(dp.begin() + K - 1, dp.end()) - dp.begin();
	cout << dp[x] << "\n";
	for (int i = K - 1; i >= 0; --i) {
		cout << x + 1 << (i ? " " : "\n");
		x = par[i][x];
	}
	return 0;
}
