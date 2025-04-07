#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n1{}, k1{}, n2{}, k2{};
	cin >> n1 >> k1 >> n2 >> k2;
	int ans = n1 * k1 + n2 * k2;
	cout << ans << "\n";
	return 0;
}
