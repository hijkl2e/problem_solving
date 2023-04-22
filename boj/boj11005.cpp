#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, B{};
	cin >> N >> B;
	string ans;
	while (N) {
		int r = N % B;
		ans += r + (r < 10 ? '0' : ('A' - 10));
		N /= B;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
