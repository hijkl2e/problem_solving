#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans{};
	for (char c : S) {
		int x = c - '0';
		ans += x * x * x * x * x;
	}
	cout << ans << "\n";
	return 0;
}
