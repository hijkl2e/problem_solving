#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	getline(cin, S);
	vector<int> A(26);
	for (char c : S) {
		++A[c - 'a'];
	}
	for (int i = 0; i < 26; ++i) {
		cout << A[i] << (i == 25 ? "\n" : " ");
	}
	return 0;
}
