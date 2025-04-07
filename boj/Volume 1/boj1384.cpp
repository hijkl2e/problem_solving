#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	for (int tc = 1; cin >> N, N; ++tc) {
		if (tc > 1) {
			cout << "\n";
		}
		vector<string> A(N);
		vector<deque<bool>> B(N, deque<bool>(N - 1));
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
			for (int j = 0; j < N - 1; ++j) {
				char c{};
				cin >> c;
				B[i][j] = (c == 'P');
			}
		}
		bool no = true;
		cout << "Group " << tc << "\n";
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N - 1; ++j) {
				if (!B[i][j]) {
					cout << A[(i - j + N - 1) % N] << " was nasty about " << A[i] << "\n";
					no = false;
				}
			}
		}
		if (no) {
			cout << "Nobody was nasty\n";
		}
	}
	return 0;
}
