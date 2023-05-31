#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	if (S.size() == 1) {
		cout << "0\n" << (S[0] % 3 == 0 ? "YES" : "NO") << "\n";
		return 0;
	}
	int x = accumulate(S.begin(), S.end(), 0) - S.size() * '0';
	int cnt = 1;
	while (x >= 10) {
		S = to_string(x);
		x = accumulate(S.begin(), S.end(), 0) - S.size() * '0';
		++cnt;
	}
	cout << cnt << "\n" << (x % 3 == 0 ? "YES" : "NO") << "\n";
	return 0;
}
