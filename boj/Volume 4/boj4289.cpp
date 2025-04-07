#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 0; cin >> N, N; ++tc) {
		int K{};
		cin >> K;
		vector<int> W(N + 1);
		vector<int> L(N + 1);
		for (int i = K * N * (N - 1) / 2; i > 0; --i) {
			int p1{}, p2{};
			string m1, m2;
			cin >> p1 >> m1 >> p2 >> m2;
			if (m1 == m2) {
				continue;
			}
			if (m1 > m2) {
				swap(p1, p2);
				swap(m1, m2);
			}
			if (m1[0] == 'p' && m2[0] == 's') {
				swap(p1, p2);
			}
			++W[p1];
			++L[p2];
		}
		if (tc) {
			cout << "\n";
		}
		cout << fixed << setprecision(3);
		for (int i = 1; i <= N; ++i) {
			int total = W[i] + L[i];
			if (total) {
				double ans = W[i] * 1.0 / (W[i] + L[i]) + EPS;
				cout << ans << "\n";
			} else {
				cout << "-\n";
			}
		}
	}
	return 0;
}
