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
	for (int i = 0; i < C; ++i) {
		int now = R - 1;
		for (int j = R - 1; j >= 0; --j) {
			if (A[j][i] == '#') {
				now = j - 1;
			} else if (A[j][i] == 'a') {
				A[j][i] = '.';
				A[now--][i] = 'a';
			}
		}
	}
	for (int i = 0; i < R; ++i) {
		cout << A[i] << "\n";
	}
	return 0;
}
