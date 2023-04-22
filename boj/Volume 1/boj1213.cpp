#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(26);
	for (char c : S) {
		++A[c - 'A'];
	}
	vector<int> B;
	for (int i = 0; i < 26; ++i) {
		if (A[i] % 2) {
			B.push_back(i);
		}
	}
	if (B.size() != S.size() % 2) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}
	string ans;
	for (int i = 0; i < 26; ++i) {
		ans += string(A[i] / 2, 'A' + i);
	}
	if (B.size()) {
		ans += string(1, 'A' + B[0]);
	}
	for (int i = 25; i >= 0; --i) {
		ans += string(A[i] / 2, 'A' + i);
	}
	cout << ans << "\n";
	return 0;
}
