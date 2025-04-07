#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, M{};
		cin >> N >> M;
		vector<int> A(N + M);
		for (int i = 0; i < N + M; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end() - 1);
		ll ans = accumulate(A.begin() + M, A.end(), 0LL);
		cout << ans << "\n";
	}
	return 0;
}
