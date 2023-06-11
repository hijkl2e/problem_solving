#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	vector<vector<int>> A(26);
	for (int i = 0; i < s.size(); ++i) {
		A[s[i] - 'a'].push_back(i);
	}
	int ans{};
	for (int i = 0; i < s.size(); ++i) {
		int now = s[i] - 'a';
		auto it = upper_bound(A[now].begin(), A[now].end(), i);
		int x = it == A[now].end() ? s.size() : *it;
		for (int j = 0; j < 26; ++j) {
			if (s[i] - 'a' == j) {
				continue;
			}
			it = upper_bound(A[j].begin(), A[j].end(), i);
			if (it != A[j].end() && *it < x) {
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
