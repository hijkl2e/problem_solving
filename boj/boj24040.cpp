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
		cout << (N % 9 == 0 || N % 3 == 2 ? "TAK" : "NIE") << "\n";
	}
	return 0;
}
