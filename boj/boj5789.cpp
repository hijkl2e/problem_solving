#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	cin.ignore();
	while (T--) {
		string S;
		getline(cin, S);
		int p = S.size() / 2;
		cout << "Do-it" << (S[p - 1] == S[p] ? "" : "-Not") << "\n";
	}
	return 0;
}
