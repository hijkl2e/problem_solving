#include <bits/stdc++.h>

using namespace std;

int solve(string &S, int &p) {
	int ret{};
	while (p < S.size()) {
		if (S[p] == '(') {
			ret = (ret - 1) + (S[p - 1] - '0') * solve(S, ++p);
		} else if (S[p] == ')') {
			break;
		} else {
			++ret;
		}
		++p;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	int p{};
	cout << solve(S, p) << "\n";
	return 0;
}
