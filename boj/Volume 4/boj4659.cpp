#include <bits/stdc++.h>

using namespace std;

bool solve(string &S) {
	deque<bool> A(S.size());
	for (int i = 0; i < S.size(); ++i) {
		char c = S[i];
		A[i] = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	if (accumulate(A.begin(), A.end(), 0) == 0) {
		return false;
	}
	for (int i = 2; i < S.size(); ++i) {
		int x = A[i - 2] + A[i - 1] + A[i];
		if (x == 0 || x == 3) {
			return false;
		}
	}
	for (int i = 1; i < S.size(); ++i) {
		if (S[i - 1] == S[i] && S[i] != 'e' && S[i] != 'o') {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "end") {
		cout << "<" << S << "> is " << (solve(S) ? "" : "not ") << "acceptable.\n";
	}
	return 0;
}
