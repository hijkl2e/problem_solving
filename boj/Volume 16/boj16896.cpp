#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		ll N{};
		cin >> N;
		bool yes = N % 2;
		for (int i = 2; i < 50; i += 2) {
			yes &= (N & (1LL << i)) == 0;
		}
		cout << (yes ? "koosaga" : "cubelover") << "\n";
	}
	return 0;
}
