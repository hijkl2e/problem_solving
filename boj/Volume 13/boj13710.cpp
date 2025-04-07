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
	ll ans{};
	for (int i = 0; i < 30; ++i) {
		int cnt{};
		for (int j = 0; j < N; ++j) {
			if (A[j] & (1LL << i)) {
				cnt = j - cnt + 1;
			}
			ans += cnt * (1LL << i);
		}
	}
	cout << ans << "\n";
	return 0;
}
