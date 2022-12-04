#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	ll ans{};
	vector<int> A(3);
	for (char c : S) {
		if (c < '2') {
			ans += A[2];
			if (c == '0') {
				ans += A[1];
			}
		}
		++A[c - '0'];
	}
	cout << ans << "\n";
	return 0;
}
