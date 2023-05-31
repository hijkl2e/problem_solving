#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int K{}, N{}, M{};
		cin >> K >> N >> M;
		bool yes = min(N, M) % (K + 1) == 0 || (N + M + (K > 1 && min(N, M) / (K + 1) % 2)) % 2;
		cout << (yes ? "koosaga" : "cubelover") << "\n";
	}
	return 0;
}
