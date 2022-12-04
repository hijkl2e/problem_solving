#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<string> A(5, string(4 * S.size() + 1, '.'));
	for (int i = 0; i < S.size(); ++i) {
		A[2][4 * i + 2] = S[i];
	}
	for (int i = 0; i < S.size(); ++i) {
		if (i % 3 == 2) {
			continue;
		}
		for (int j = 0; j < 8; ++j) {
			A[4 - abs(4 - j)][4 - abs(4 - (j + 2) % 8) + 4 * i] = '#';
		}
	}
	for (int i = 2; i < S.size(); i += 3) {
		for (int j = 0; j < 8; ++j) {
			A[4 - abs(4 - j)][4 - abs(4 - (j + 2) % 8) + 4 * i] = '*';
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}
