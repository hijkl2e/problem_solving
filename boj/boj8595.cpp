#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	string S;
	getline(cin, S);
	ll ans{}, x{};
	for (char c : S) {
		if (isalpha(c)) {
			ans += x;
			x = 0;
		} else {
			x = 10 * x + c - '0';
		}
	}
	ans += x;
	cout << ans << "\n";
	return 0;
}
