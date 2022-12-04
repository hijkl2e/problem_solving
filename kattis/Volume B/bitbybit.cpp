#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N, N) {
		vector<int> A(32, -1);
		while (N--) {
			string cmd;
			int x{}, y{};
			cin >> cmd >> x;
			if (cmd == "CLEAR") {
				A[x] = 0;
			} else if (cmd == "SET") {
				A[x] = 1;
			} else {
				cin >> y;
				if (cmd == "OR") {
					if (A[y] == 1) {
						A[x] = 1;
					} else if (A[x] == 0 && A[y] == -1) {
						A[x] = -1;
					}
				} else {
					if (A[y] == 0) {
						A[x] = 0;
					} else if (A[x] == 1 && A[y] == -1) {
						A[x] = -1;
					}
				}
			}
		}
		for (int i = 31; i >= 0; --i) {
			if (A[i] == -1) {
				cout << "?";
			} else {
				cout << A[i];
			}
		}
		cout << "\n";
	}
	return 0;
}
