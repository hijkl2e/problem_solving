#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	int cnt{};
	for (ll i = 2; i * i <= N; ++i) {
		while (N % i == 0) {
			N /= i;
			++cnt;
		}
	}
	if (N > 1) {
		++cnt;
	}
	cout << (cnt == 2 ? "cubelover" : "koosaga") << "\n";
	return 0;
}
