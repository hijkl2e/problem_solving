#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	sort(A.begin(), A.end());
	int K{};
	cin >> K;
	int ans{};
	for (int i = 0, j = 1; i < N; i = j++) {
		while (j < N && A[i] == A[j]) {
			++j;
		}
		int cnt = count(A[i].begin(), A[i].end(), '0');
		if (cnt > K || (K - cnt) % 2) {
			continue;
		}
		ans = max(ans, j - i);
	}
	cout << ans << "\n";
	return 0;
}
