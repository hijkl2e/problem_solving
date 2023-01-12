#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, x{};
	cin >> N >> x;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = N;
	for (int i = 0; i < N; ++i) {
		if (x < A[i] + 1) {
			ans = i;
			break;
		}
		x -= A[i] + 1;
	}
	cout << ans << "\n";
	return 0;
}
