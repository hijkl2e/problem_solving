#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{};
	cin >> L;
	cin.ignore();
	string S;
	getline(cin, S);
	ll ans{};
	for (int i = L - 1; i >= 0; --i) {
		ans = (31 * ans + S[i] - 'a' + 1) % 1234567891;
	}
	cout << ans << "\n";
	return 0;
}
