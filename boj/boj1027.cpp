#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	vector<deque<bool>> A(N, deque<bool>(N));
	for (int i = 0; i < N - 1; ++i) {
		A[i][i + 1] = A[i + 1][i] = true;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = i + 2; j < N; ++j) {
			ll a = H[j] - H[i];
			ll b = j * H[i] - i * H[j];
			bool yes = true;
			for (int k = i + 1; k < j; ++k) {
				if (a * k + b <= (j - i) * H[k]) {
					yes = false;
					break;
				}
			}
			A[i][j] = A[j][i] = yes;
		}
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		ans = max(ans, accumulate(A[i].begin(), A[i].end(), 0));
	}
	cout << ans << "\n";
	return 0;
}
