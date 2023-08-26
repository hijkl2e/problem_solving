#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		vector<ll> x(4);
		vector<ll> y(4);
		for (int i = 0; i < 4; ++i) {
			cin >> x[i] >> y[i];
		}
		vector<ll> A;
		for (int i = 0; i < 4; ++i) {
			for (int j = i + 1; j < 4; ++j) {
				A.push_back((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
			}
		}
		sort(A.begin(), A.end());
		cout << (A[0] == A[3] && A[4] == A[5] && 2 * A[0] == A[4]) << "\n";
	}
	return 0;
}
