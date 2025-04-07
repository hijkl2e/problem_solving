#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A(26);
	string S;
	while (getline(cin, S)) {
		for (char c : S) {
			if (islower(c)) {
				++A[c - 'a'];
			}
		}
	}
	int maxv = *max_element(A.begin(), A.end());
	for (int i = 0; i < 26; ++i) {
		if (A[i] == maxv) {
			char c = i + 'a';
			cout << c;
		}
	}
	cout << "\n";
	return 0;
}
