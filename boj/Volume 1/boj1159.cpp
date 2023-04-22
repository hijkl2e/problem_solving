#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<int> A(26);
	while (N--) {
		string s;
		getline(cin, s);
		++A[s[0] - 'a'];
	}
	string ans;
	for (int i = 0; i < 26; ++i) {
		if (A[i] >= 5) {
			ans += i + 'a';
		}
	}
	if (ans.empty()) {
		ans = "PREDAJA";
	}
	cout << ans << "\n";
	return 0;
}
