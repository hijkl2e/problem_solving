#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<vector<string>> A(26);
	int N{};
	cin >> N;
	cin.ignore();
	while (N--) {
		string s;
		getline(cin, s);
		A[s[0] - 'a'].push_back(s);
	}
	string ans = "?";
	auto &v = A[S.back() - 'a'];
	if (v.size()) {
		ans = v.front();
		for (auto &s : v) {
			if (A[s.back() - 'a'].size() == (s.front() == s.back())) {
				ans = s + "!";
				break;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
