#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N, vector<int>(4));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> A[i][j];
		}
	}
	vector<int> B(9);
	for (int i = 1; i < 9; ++i) {
		B[i] = i;
	}
	set<int> S{1236, 1245, 1348, 1568, 2347, 2567, 3678, 4578};
	bool yes{};
	vector<int> C(4);
	do {
		yes = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 4; ++j) {
				C[j] = B[A[i][j]];
			}
			sort(C.begin(), C.end());
			int x{};
			for (int i = 0; i < 4; ++i) {
				x = 10 * x + C[i];
			}
			if (S.find(x) == S.end()) {
				yes = false;
				break;
			}
		}
		if (yes) {
			break;
		}
	} while (next_permutation(B.begin() + 1, B.end()));
	cout << (yes ? "Hmm..." : "You're gonna die!") << "\n";
	return 0;
}
