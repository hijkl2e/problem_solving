#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{};
	string S;
	cin >> H >> S;
	int ans = 1;
	for (char c : S) {
		ans = 2 * ans + (c == 'R');
	}
	ans = (2 << H) - ans;
	cout << ans << "\n";
	return 0;
}
