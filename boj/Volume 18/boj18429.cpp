#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = i;
	}
	int ans{};
	do {
		int x = 500;
		for (int i = 0; i < N && x >= 500; ++i) {
			x += A[B[i]] - K;
		}
		if (x >= 500) {
			++ans;
		}
	} while (next_permutation(B.begin(), B.end()));
	cout << ans << "\n";
	return 0;
}
