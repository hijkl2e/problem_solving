#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	int ans{};
	for (int i = 0; N > 0; ++i) {
		N -= 1LL << max(i - 1, 0);
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
