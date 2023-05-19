#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, X{};
	cin >> N >> X;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = N;
	for (int i = 1; i < N; ++i) {
		if (A[i - 1] + A[i] > X) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
