#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, A{}, B{};
	cin >> N >> A >> B;
	deque<bool> C(A);
	ll ans = N + 1;
	for (int i = 0; i < A && i * B <= N; ++i) {
		int r = i * B % A;
		if (C[r]) {
			break;
		}
		C[r] = true;
		ans -= (N - i * B) / A + 1;
	}
	cout << ans << "\n";
	return 0;
}
