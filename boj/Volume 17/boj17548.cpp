#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	string ans(2 * (S.size() - 2), 'e');
	ans = "h" + ans + "y";
	cout << ans << "\n";
	return 0;
}
