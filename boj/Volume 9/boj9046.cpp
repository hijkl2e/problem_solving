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
		vector<int> A(26);
		for (char c : S) {
			if (isalpha(c)) {
				++A[c - 'a'];
			}
		}
		int p = max_element(A.begin(), A.end()) - A.begin();
		if (count(A.begin(), A.end(), A[p]) == 1) {
			char c = 'a' + p;
			cout << c << "\n";
		} else {
			cout << "?\n";
		}
	}
	return 0;
}
