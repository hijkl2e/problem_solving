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
	for (int k = 0; k < 2; ++k) {
		int ans{}, maxv{};
		for (int i = 0; i < N; ++i) {
			if (maxv < A[i]) {
				maxv = A[i];
				++ans;
			}
		}
		cout << ans << "\n";
		reverse(A.begin(), A.end());
	}
	return 0;
}
