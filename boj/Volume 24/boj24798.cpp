#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int l{}, w{};
	cin >> l >> w;
	if (w < l || 26 * l < w) {
		cout << "impossible\n";
		return 0;
	}
	string ans(l, 'a' + w / l - 1);
	for (int i = w % l - 1; i >= 0; --i) {
		++ans[i];
	}
	cout << ans << "\n";
	return 0;
}
