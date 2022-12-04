#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		cin.ignore();
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			getline(cin, A[i]);
		}
		for (int i = 0; i < M; ++i) {
			int cnt{};
			for (int j = 0; j < N; ++j) {
				cnt += A[j][i] - '0';
			}
			cout << cnt / (N / 2 + 1);
		}
		cout << "\n";
	}
	return 0;
}
