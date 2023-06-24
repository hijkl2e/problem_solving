#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		int sum = accumulate(A.begin(), A.end(), 0);
		double avg = sum * 1.0 / N;
		int cnt{};
		for (int i = 0; i < N; ++i) {
			if (A[i] > avg + EPS) {
				++cnt;
			}
		}
		double ans = cnt * 100.0 / N + EPS;
		cout << fixed << setprecision(3);
		cout << ans << "%\n";
	}
	return 0;
}
