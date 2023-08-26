#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "*") {
		deque<bool> A(26);
		for (char c : S) {
			if (islower(c)) {
				A[c - 'a'] = true;
			}
		}
		cout << (accumulate(A.begin(), A.end(), 0) == 26 ? "Y" : "N") << "\n";
	}
	return 0;
}
