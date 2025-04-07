#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, S{};
	cin >> N >> K >> S;
	vector<int> A(100001);
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		A[x] = y;
	}
	vector<int> B(A.begin(), A.end());
	reverse(B.begin(), B.end());
	int ans{};
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < S; ++i) {
			if (A[i] > K) {
				ans += (S - i) * (A[i] / K);
				A[i] %= K;
			}
			if (A[i] == 0) {
				continue;
			}
			int cnt = K;
			for (int j = i; j < S && cnt; ++j) {
				int y = min(cnt, A[j]);
				cnt -= y;
				A[j] -= y;
			}
			ans += S - i;
		}
		S = 100000 - S;
		swap(A, B);
	}
	ans *= 2;
	cout << ans << "\n";
	return 0;
}
