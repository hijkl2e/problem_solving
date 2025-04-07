#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(53);
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		++A[x];
	}
	cin.ignore();
	string S;
	getline(cin, S);
	for (char c : S) {
		if (isupper(c)) {
			--A[c - 'A' + 1];
		} else if (islower(c)) {
			--A[c - 'a' + 27];
		} else {
			--A[0];
		}
	}
	bool yes = (count(A.begin(), A.end(), 0) == 53);
	cout << (yes ? "y" : "n") << "\n";
	return 0;
}
