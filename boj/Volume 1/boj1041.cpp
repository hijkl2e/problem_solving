#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{};
	cin >> N;
	vector<int> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i];
	}
	if (N == 1) {
		int ans = accumulate(A.begin(), A.end(), 0) - *max_element(A.begin(), A.end());
		cout << ans << "\n";
		return 0;
	}
	vector<int> B(3, INF);
	B[0] = *min_element(A.begin(), A.end());
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j) {
			if (i + j == 5) {
				continue;
			}
			B[1] = min(B[1], A[i] + A[j]);
		}
	}
	swap(A[3], A[4]);
	for (int i = 1; i < 5; ++i) {
		B[2] = min(B[2], min(A[0], A[5]) + A[i] + A[i % 4 + 1]);
	}
	ll ans = 4 * ((N - 1) * (N - 2) * B[0] + (2 * N - 3) * B[1] + B[2]) + (N - 2) * (N - 2) * B[0];
	cout << ans << "\n";
	return 0;
}
