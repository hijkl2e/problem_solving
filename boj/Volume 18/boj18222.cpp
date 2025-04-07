#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll K{};
	cin >> K;
	cout << __builtin_popcountll(K - 1) % 2 << "\n";
	return 0;
}
