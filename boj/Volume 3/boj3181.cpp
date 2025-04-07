#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	set<string> A{
		"i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili"
	};
	vector<string> B;
	string S;
	while (cin >> S) {
		B.push_back(S);
	}
	string ans;
	for (int i = 0; i < B.size(); ++i) {
		if (i && A.count(B[i])) {
			continue;
		}
		ans += toupper(B[i][0]);
	}
	cout << ans << "\n";
	return 0;
}
