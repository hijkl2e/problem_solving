#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{};
		cin >> N;
		vector<ll> A(N);
		for (int i = 0; i < N; ++i) {
			int M{};
			cin >> M;
			while (M--) {
				int x{};
				cin >> x;
				A[i] += x;
			}
		}
		sort(A.begin(), A.end());
		ll sum{};
		for (int i = 0; i < N; ++i) {
			sum += (N - i) * A[i];
		}
		double avg = sum * 1.0 / N;
		cout << fixed << setprecision(10);
		cout << avg << "\n";
	}
	return 0;
}
