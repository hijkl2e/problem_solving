#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, S{};
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans{};
	for (int i = 1; i < (1 << N); ++i) {
		int sum{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				sum += A[j];
			}
		}
		if (sum == S) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
