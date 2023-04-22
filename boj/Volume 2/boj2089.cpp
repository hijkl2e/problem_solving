#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	string ans;
	while (N) {
		int r = abs(N % 2);
		ans += to_string(r);
		N = (r - N) / 2;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
