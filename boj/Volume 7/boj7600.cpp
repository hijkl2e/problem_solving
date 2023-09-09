#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S), S != "#") {
		deque<bool> A(26);
		for (char c : S) {
			if (isalpha(c)) {
				A[tolower(c) - 'a'] = true;
			}
		}
		int ans = accumulate(A.begin(), A.end(), 0);
		cout << ans << "\n";
	}
	return 0;
}
