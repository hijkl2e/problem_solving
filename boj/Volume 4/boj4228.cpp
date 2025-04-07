#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int ans{};
		for (int i = 0, j = 0; i < N; ++i) {
			while (j < M && A[i] > B[j]) {
				++j;
			}
			if (j == M) {
				ans = -1;
				break;
			}
			ans += B[j++];
		}
		if (ans == -1) {
			cout << "Loowater is doomed!\n";
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}
