#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int R{}, C{};
		cin >> R >> C;
		cin.ignore();
		vector<string> A(R);
		for (int i = 0; i < R; ++i) {
			getline(cin, A[i]);
		}
		cout << "Test " << tc << "\n";
		for (int i = R - 1; i >= 0; --i) {
			for (int j = C - 1; j >= 0; --j) {
				cout << A[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
