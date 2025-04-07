#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A, B;
	while (N--) {
		int x{};
		cin >> x;
		if (x > 0) {
			A.push_back(x);
		} else {
			B.push_back(x);
		}
	}
	sort(A.begin(), A.end());
	sort(B.rbegin(), B.rend());
	ll ans{};
	for (int i = A.size() % 2; i < A.size(); i += 2) {
		ans += max(A[i] * A[i + 1], A[i] + A[i + 1]);
	}
	for (int i = B.size() % 2; i < B.size(); i += 2) {
		ans += B[i] * B[i + 1];
	}
	if (A.size() % 2) {
		ans += A[0];
	}
	if (B.size() % 2) {
		ans += B[0];
	}
	cout << ans << "\n";
	return 0;
}
