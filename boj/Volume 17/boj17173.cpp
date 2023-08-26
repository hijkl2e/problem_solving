#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		bool yes{};
		for (int j = 0; j < M; ++j) {
			if (i % A[j] == 0) {
				yes = true;
				break;
			}
		}
		if (yes) {
			ans += i;
		}
	}
	cout << ans << "\n";
	return 0;
}
