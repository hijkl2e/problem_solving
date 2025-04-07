#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int x{};
	cin >> x;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		if (A[i]) {
			ans += ((A[i] - 1) / x + 1) * x;
		}
	}
	cout << ans << "\n";
	return 0;
}
