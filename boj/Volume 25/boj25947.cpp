#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, b{}, a{};
	cin >> N >> b >> a;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = N, sum{};
	for (int i = 0; i < N; ++i) {
		if (i < a) {
			sum += A[i] / 2;
		} else {
			sum += A[i] / 2 + A[i - a] / 2;
		}
		if (sum > b) {
			ans = i;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
