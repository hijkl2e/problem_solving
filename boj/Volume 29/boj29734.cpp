#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{}, T{}, S{};
	cin >> N >> M >> T >> S;
	ll x = N + (N - 1) / 8 * S;
	ll y = M + (M - 1) / 8 * (2 * T + S) + T;
	cout << (x < y ? "Zip" : "Dok") << "\n";
	cout << min(x, y) << "\n";
	return 0;
}
