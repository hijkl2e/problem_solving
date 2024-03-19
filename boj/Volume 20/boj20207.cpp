#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(367);
	while (N--) {
		int s{}, e{};
		cin >> s >> e;
		++A[s], --A[e + 1];
	}
	partial_sum(A.begin(), A.end(), A.begin());
	int ans{};
	for (int i = 1, j = 2; i < 366; i = j++) {
		if (A[i] == 0) {
			continue;
		}
		int maxv = A[i];
		while (j < 366 && A[j]) {
			maxv = max(maxv, A[j++]);
		}
		ans += (j - i) * maxv;
	}
	cout << ans << "\n";
	return 0;
}
