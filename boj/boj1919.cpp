#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	vector<int> A(26);
	for (char c : s1) {
		++A[c - 'a'];
	}
	for (char c : s2) {
		--A[c - 'a'];
	}
	int ans{};
	for (int i = 0; i < 26; ++i) {
		ans += abs(A[i]);
	}
	cout << ans << "\n";
	return 0;
}
