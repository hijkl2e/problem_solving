#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int R{}, C{};
		cin >> R >> C;
		cin.ignore();
		vector<string> A(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, A[i]);
		}
		for (int i = 0; i < R; ++i) {
			reverse(A[i].begin(), A[i].end());
		}
		for (int i = 0; i < R; ++i) {
			cout << A[i] << "\n";
		}
	}
	return 0;
}
