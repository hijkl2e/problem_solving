#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int n{}, a{}, b{};
		cin >> n >> a >> b;
		cout << ((a == n && b == n) || a + b < n - 1 ? "Yes" : "No") << "\n";
	}
	return 0;
}
