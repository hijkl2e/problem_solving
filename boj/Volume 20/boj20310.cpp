#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	deque<bool> A(S.size(), true);
	int cnt = count(S.begin(), S.end(), '1') / 2;
	for (int i = 0, j = 0; i < S.size(); ++i) {
		if (S[i] == '1') {
			A[i] = false;
			if (++j == cnt) {
				break;
			}
		}
	}
	cnt = count(S.begin(), S.end(), '0') / 2;
	for (int i = S.size() - 1, j = 0; i >= 0; --i) {
		if (S[i] == '0') {
			A[i] = false;
			if (++j == cnt) {
				break;
			}
		}
	}
	for (int i = 0; i < S.size(); ++i) {
		if (A[i]) {
			cout << S[i];
		}
	}
	cout << "\n";
	return 0;
}
