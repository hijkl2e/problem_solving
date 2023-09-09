#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int ans = S.size() + 5 * count(S.begin(), S.end(), '_') + 2;
	cout << ans << "\n";
	return 0;
}
