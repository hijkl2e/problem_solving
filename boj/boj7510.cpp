#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	vector<ll> A(3);
	for (int tc = 1; tc <= T; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		for (int i = 0; i < 3; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		bool yes = A[0] * A[0] + A[1] * A[1] == A[2] * A[2];
		cout << "Scenario #" << tc << ":\n" << (yes ? "yes" : "no") << "\n";
	}
	return 0;
}
