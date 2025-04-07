#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	string ans = string(K, '1') + string(K - 1, '0');
	cout << ans << "\n";
	return 0;
}
