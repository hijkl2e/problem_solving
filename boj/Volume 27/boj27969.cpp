#include <bits/stdc++.h>

using namespace std;

int solve(string &S, int &p) {
	int ret = 8;
	p += 2;
	while (true) {
		if (S[p] == '[') {
			ret += solve(S, p);
		} else if (S[p] == ']') {
			p += 2;
			break;
		} else if (isdigit(S[p])) {
			ret += 8;
			while (isdigit(S[p])) {
				++p;
			}
			++p;
		} else {
			ret += 12;
			while (isalpha(S[p])) {
				++ret, ++p;
			}
			++p;
		}
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
