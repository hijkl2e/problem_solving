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
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int ans{};
		for (int i = 0; i < N; ++i) {
			if (A[i] != M) {
				continue;
			}
			int sum = M;
			for (int j = i + 1; j < N && A[j] > M; ++j) {
				sum += A[j];
			}
			for (int j = i - 1; j >= 0 && A[j] > M; --j) {
				sum += A[j];
			}
			ans = max(ans, sum);
		}
		cout << ans << "\n";
	}
	return 0;
}
