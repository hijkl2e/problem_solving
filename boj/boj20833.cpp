#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N * (N + 1) / 2;
	ans *= ans;
	cout << ans << "\n";
	return 0;
}
