#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<string> A(5);
	for (int i = 0; i < 5; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i < A[j].size()) {
				cout << A[j][i];
			}
		}
	}
	cout << "\n";
	return 0;
}
