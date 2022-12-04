#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	deque<bool> A(N + 1);
	ll ans{};
	for (int i = 2; i <= N; ++i) {
		if (A[i]) {
			continue;
		}
		for (int j = i; j <= N; j += i) {
			ans += A[j] ? 0 : i;
			A[j] = true;
		}
	}
	cout << ans << "\n";
	return 0;
}
