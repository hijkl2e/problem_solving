#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(26);
	for (int tc = 1;; ++tc) {
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		if (s1 == "END" && s2 == "END") {
			break;
		}
		fill(A.begin(), A.end(), 0);
		for (char c : s1) {
			++A[c - 'a'];
		}
		for (char c : s2) {
			--A[c - 'a'];
		}
		cout << "Case " << tc << ": ";
		cout << (count(A.begin(), A.end(), 0) == 26 ? "same" : "different") << "\n";
	}
	return 0;
}
