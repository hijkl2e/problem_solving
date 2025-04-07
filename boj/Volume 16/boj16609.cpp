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
	sort(A.begin(), A.end());
	double ans = 1;
	for (int i = 0; i < N; ++i) {
		if (A[i] > i + 1) {
			ans = -1;
			break;
		}
		ans = min(ans, A[i] * 1.0 / (i + 1));
	}
	if (ans == -1) {
		cout << "impossible\n";
	} else {
		cout << fixed << setprecision(10);
		cout << ans << "\n";
	}
	return 0;
}
