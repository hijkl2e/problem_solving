#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A;
	vector<int> B;
	for (int i = 0; i < N; ++i) {
		int x{};
		cin >> x;
		if (x % 10) {
			A.push_back(x);
		} else {
			B.push_back(x);
		}
	}
	sort(B.begin(), B.end());
	int ans{};
	for (int i = 0; i < B.size() && M; ++i) {
		while (B[i] > 10 && M) {
			B[i] -= 10;
			++ans;
			--M;
		}
		if (B[i] == 10) {
			++ans;
		}
	}
	for (int i = 0; i < A.size() && M; ++i) {
		int cnt = min(A[i] / 10, M);
		ans += cnt;
		M -= cnt;
	}
	cout << ans << "\n";
	return 0;
}
