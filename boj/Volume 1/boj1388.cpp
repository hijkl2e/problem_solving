#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		bool f{};
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == '-') {
				f = true;
			} else {
				ans += f;
				f = false;
			}
		}
		ans += f;
	}
	for (int j = 0; j < M; ++j) {
		bool f{};
		for (int i = 0; i < N; ++i) {
			if (A[i][j] == '|') {
				f = true;
			} else {
				ans += f;
				f = false;
			}
		}
		ans += f;
	}
	cout << ans << "\n";
	return 0;
}
