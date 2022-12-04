#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<int> A(N);
		vector<int> B(M);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		for (int i = 0; i < M; ++i) {
			cin >> B[i];
		}
		int ans{};
		for (int i = 0, j = 0; i < N && j < M;) {
			if (A[i] < B[j]) {
				++i;
			} else if (A[i] > B[j]) {
				++j;
			} else {
				++i, ++j;
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
