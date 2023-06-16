#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	for (int i = 63 - __builtin_clzll(N); i >= 0; --i) {
		cout << ((N >> i) & 1);
	}
	cout << "\n";
	return 0;
}
