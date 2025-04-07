#include <bits/stdc++.h>

using namespace std;

int N;
string S;

bool solve(int n) {
	if (n == N) {
		return true;
	}
	for (int i = 1; i < 4; ++i) {
		S[n] = i + '0';
		bool yes = true;
		for (int j = 1; n - 2 * j + 1 >= 0; ++j) {
			if (S.substr(n - 2 * j + 1, j) == S.substr(n - j + 1, j)) {
				yes = false;
				break;
			}
		}
		if (yes && solve(n + 1)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	S = string(N, ' ');
	solve(0);
	cout << S << "\n";
	return 0;
}
