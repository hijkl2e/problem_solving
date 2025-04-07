#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> B(2000001);
	for (int i = 0; i < (1 << N); ++i) {
		int sum{};
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				sum += A[j];
			}
		}
		B[sum] = true;
	}
	int ans{};
	for (int i = 0; B[i]; ++i) {
		ans = i + 1;
	}
	cout << ans << "\n";
	return 0;
}
