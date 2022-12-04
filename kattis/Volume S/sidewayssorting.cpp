#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int R{}, C{};
	for (int tc = 0; cin >> R >> C, R; ++tc) {
		vector<string> A(C, string(' ', R));
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cin >> A[j][i];
			}
		}
		stable_sort(A.begin(), A.end(), [](const string &s1, const string &s2) {
			for (int i = 0; i < s1.size(); ++i) {
				char c1 = tolower(s1[i]);
				char c2 = tolower(s2[i]);
				if (c1 < c2) {
					return true;
				} else if (c1 > c2) {
					return false;
				}
			}
			return false;
		});
		if (tc) {
			cout << "\n";
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << A[j][i];
			}
			cout << "\n";
		}
	}
	return 0;
}
