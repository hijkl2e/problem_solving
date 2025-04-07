#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<char> A{'A', 'D', 'G', 'J', 'M', 'P', 'T', 'W'};
	string S;
	getline(cin, S);
	int ans{};
	for (char c : S) {
		ans += upper_bound(A.begin(), A.end(), c) - A.begin() + 2;
	}
	cout << ans << "\n";
	return 0;
}
