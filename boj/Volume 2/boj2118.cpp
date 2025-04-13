#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(2 * N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	copy(A.begin(), A.begin() + N, A.begin() + N);
	int S = accumulate(A.begin(), A.begin() + N, 0);
	int s{}, e{}, sum{}, ans{};
	while (s < N) {
		if (sum < S / 2) {
			sum += A[e++];
		} else {
			sum -= A[s++];
		}
		ans = max(ans, min(sum, S - sum));
	}
	cout << ans << "\n";
	return 0;
}
