#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int cnt = 1;
	for (int i = 1; i < S.size(); ++i) {
		if (S[i] != S[i - 1]) {
			++cnt;
		}
	}
	cout << cnt / 2 << "\n";
	return 0;
}
