#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	vector<string> B(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	for (int i = 0; i < N; ++i) {
		getline(cin, B[i]);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == B[i][j]) {
				continue;
			} else if (i + 3 > N || j + 3 > M) {
				ans = -1;
				i = N;
				break;
			}
			for (int k = 0; k < 3; ++k) {
				for (int l = 0; l < 3; ++l) {
					A[i + k][j + l] ^= 1;
				}
			}
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
