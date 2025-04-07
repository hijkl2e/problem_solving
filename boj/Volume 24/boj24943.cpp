#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

vector<ii> solve(vector<ll> &A) {
	vector<ii> B;
	for (int i = 0; i < A.size(); ++i) {
		ll r = A[i], h = 1;
		while (B.size()) {
			auto &[u, v] = B.back();
			if (u * h < v * r) {
				break;
			}
			r += u, h += v;
			B.pop_back();
		}
		B.push_back({r, h});
	}
	return B;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N);
	vector<ll> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<ll> R(--N);
	vector<ll> C(--M);
	for (int i = 0; i < N; ++i) {
		R[i] = A[i] - A[i + 1];
	}
	reverse(R.begin(), R.end());
	for (int i = 0; i < M; ++i) {
		C[i] = B[i + 1] - B[i];
	}
	vector<ii> D = solve(R);
	vector<ii> E = solve(C);
	ll ans = N * B[0] + M * A[N];
	ll sum{}, cnt{};
	for (auto &[u, v] : E) {
		sum += u, cnt += v;
	}
	for (int i = 0, j = E.size() - 1; i < D.size(); ++i) {
		auto &[a, b] = D[i];
		while (j >= 0) {
			auto &[u, v] = E[j];
			if (a * v + b * u > 0) {
				sum -= u, cnt -= v, --j;
			} else {
				break;
			}
		}
		ans += a * cnt + b * sum;
	}
	cout << ans << "\n";
	return 0;
}
