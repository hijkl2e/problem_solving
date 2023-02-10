#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	getline(cin, S);
	getline(cin, T);
	vector<int> A(27);
	for (char c : S) {
		int idx = c == ' ' ? 26 : (c - 'a');
		--A[idx];
	}
	for (char c : T) {
		int idx = c == ' ' ? 26 : (c - 'a');
		++A[idx];
	}
	for (int i = 0; i < 27; ++i) {
		if (A[i]) {
			char c = i == 26 ? ' ' : (i + 'a');
			cout << c;
		}
	}
	cout << "\n";
	return 0;
}
