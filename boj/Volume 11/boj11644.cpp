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
		bool yes = true;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == '0') {
					continue;
				}
				for (int k = 0; k < R; ++k) {
					for (int l = 0; l < C; ++l) {
						if (A[k][l] == '1' && (A[i][l] == '0' || A[k][j] == '0')) {
							yes = false;
						}
					}
				}
			}
		}
		if (!yes) {
			cout << "impossible\n";
			cout << string(10, '-') << "\n";
			continue;
		}
		vector<int> rfreq(R);
		vector<int> cfreq(C);
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (A[i][j] == '1') {
					++rfreq[i];
					++cfreq[j];
				}
			}
		}
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				cout << (A[i][j] == '0' ? "N" : (rfreq[i] == 1 || cfreq[j] == 1 ? "P" : "I"));
			}
			cout << "\n";
		}
		cout << string(10, '-') << "\n";
	}
	return 0;
}
