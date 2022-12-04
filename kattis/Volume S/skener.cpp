#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{}, Zr{}, Zc{};
	cin >> R >> C >> Zr >> Zc;
	cin.ignore();
	vector<string> A(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < R; ++i) {
		for (int k = 0; k < Zr; ++k) {
			for (int j = 0; j < C; ++j) {
				for (int l = 0; l < Zc; ++l) {
					cout << A[i][j];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
