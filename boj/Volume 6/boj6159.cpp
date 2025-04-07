#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int s = 0, e = N - 1;
	int ans{};
	while (s < e) {
		if (A[s] + A[e] > M) {
			--e;
		} else {
			ans += e - s++;
		}
	}
	cout << ans << "\n";
	return 0;
}
