#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	vector<int> A(1e6 + 1);
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (A[H[i]]) {
			--A[H[i]];
		} else {
			++ans;
		}
		++A[H[i] - 1];
	}
	cout << ans << "\n";
	return 0;
}
