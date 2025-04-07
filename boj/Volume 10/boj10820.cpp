#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	while (getline(cin, S)) {
		vector<int> A(4);
		for (char c : S) {
			++A[islower(c) ? 0 : isupper(c) ? 1 : isdigit(c) ? 2 : 3];
		}
		for (int i = 0; i < 4; ++i) {
			cout << A[i] << (i == 3 ? "\n" : " ");
		}
	}
	return 0;
}
