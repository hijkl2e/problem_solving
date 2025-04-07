#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	while (T--) {
		int N{}, K{};
		cin >> N >> K;
		vector<ii> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i].first >> A[i].second;
		}
		if (K <= A[0].first) {
			cout << "YES\n";
			continue;
		} else if (K > A[0].first + A[0].second) {
			cout << "NO\n";
			continue;
		}
		sort(A.begin() + 1, A.end(), [](ii &a, ii &b) {
			return a.first + a.second > b.first + b.second;
		});
		int goal = K - A[0].second;
		bool yes{};
		for (int i = 1; i < N; ++i) {
			if (A[i].first + A[i].second < goal) {
				break;
			} else if (A[i].first >= goal
					|| (i + 1 < N && A[i + 1].first + A[i + 1].second >= goal)) {
				yes = true;
				break;
			} else {
				goal -= A[i].second;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
