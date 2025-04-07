#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A{
		"000", "001", "010", "011", "100", "101", "110", "111"
	};
	string S;
	getline(cin, S);
	if (S == "0") {
		cout << "0\n";
		return 0;
	}
	string ans;
	for (char c : S) {
		ans += A[c - '0'];
	}
	while (ans[0] == '0') {
		ans.erase(ans.begin());
	}
	cout << ans << "\n";
	return 0;
}
