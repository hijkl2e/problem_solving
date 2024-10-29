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
		int x{}, y{};
		for (int i = 0; i < M; ++i) {
			int k{};
			cin >> k;
			x = 10 * x + k;
		}
		for (int i = 0; i < M; ++i) {
			int k{};
			cin >> k;
			y = 10 * y + k;
		}
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int z{}, m = 1;
		for (int i = N - M; i < N; ++i) {
			z = 10 * z + A[i];
			m *= 10;
		}
		m /= 10;
		int ans{};
		for (int i = 0; i < N; ++i) {
			z = 10 * (z % m) + A[i];
			if (x <= z && z <= y) {
				++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
