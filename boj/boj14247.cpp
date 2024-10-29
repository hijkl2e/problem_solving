#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	ll ans{};
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		ans += x;
	}
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; ++i) {
		ans += i * A[i];
	}
	cout << ans << "\n";
	return 0;
}
