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
	int maxv{}, ans{};
	for (int i = N - 1; i >= 0; --i) {
		if (maxv < A[i]) {
			maxv = A[i];
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
