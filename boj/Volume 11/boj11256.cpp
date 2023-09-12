#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> M >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			int r{}, c{};
			cin >> r >> c;
			A[i] = r * c;
		}
		sort(A.rbegin(), A.rend());
		int ans{};
		for (int i = 0; i < N && M > 0; ++i) {
			M -= A[i];
			++ans;
		}
		cout << ans << "\n";
	}
	return 0;
}
