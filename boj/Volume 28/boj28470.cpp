#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<int> K(N);
	for (int i = 0; i < N; ++i) {
		double x{};
		cin >> x;
		K[i] = 10 * x + EPS;
	}
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ans += max(A[i] * K[i] / 10 - B[i], A[i] - B[i] * K[i] / 10);
	}
	cout << ans << "\n";
	return 0;
}
