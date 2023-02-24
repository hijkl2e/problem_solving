#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> B(63);
	vector<ll> T(80);
	B[0] = T[0] = 1;
	for (int i = 1; i < B.size(); ++i) {
		B[i] = 2 * B[i - 1];
	}
	for (int i = 1; i < T.size(); ++i) {
		T[i] = i % 2 ? (2 * T[i - 1]) : (3 * T[i - 2]);
	}
	int Q{};
	cin >> Q;
	while (Q--) {
		ll N{};
		cin >> N;
		cout << upper_bound(B.begin(), B.end(), N) - B.begin() - 1 << " ";
		cout << upper_bound(T.begin(), T.end(), N) - T.begin() - 1 << "\n";
	}
	return 0;
}
