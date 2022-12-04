#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 1, 2, 3, -1, 1, 2, -1, -1, 2, 2, 4, 5,
		5, -1, 1, 2, 6, 2, 3, -1, 1, -1, 2, -1, 2
	};
	string S;
	while (getline(cin, S)) {
		int prev = -1;
		for (char c : S) {
			int idx = c - 'A';
			if (A[idx] != -1 && prev != A[idx]) {
				cout << A[idx];
			}
			prev = A[idx];
		}
		cout << "\n";
	}
	return 0;
}
