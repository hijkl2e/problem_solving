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
	while (M--) {
		int s{}, e{};
		cin >> s >> e;
		if (s > e) {
			swap(s, e);
		}
		int ans = upper_bound(A.begin(), A.end(), e) - lower_bound(A.begin(), A.end(), s);
		cout << ans << "\n";
	}
	return 0;
}
