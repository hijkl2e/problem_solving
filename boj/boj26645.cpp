#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	int ans = N > 228 ? 4 : N > 217 ? 3 : N > 205 ? 2 : 1;
	cout << ans << "\n";
	return 0;
}
