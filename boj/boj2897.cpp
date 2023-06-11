#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	cin >> R >> C;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	vector<int> B(5);
	for (int i = 0; i < R - 1; ++i) {
		for (int j = 0; j < C - 1; ++j) {
			bool yes = true;
			int cnt{};
			for (int k = 0; k < 2; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (A[i + k][j + l] == '#') {
						yes = false;
					} else if (A[i + k][j + l] == 'X') {
						++cnt;
					}
				}
			}
			if (yes) {
				++B[cnt];
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
