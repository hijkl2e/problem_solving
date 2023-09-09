#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(), A.end());
	int ans{}, sum{};
	for (int i = 0, j = 0; i < N; ++i) {
		while (j < N && A[j].first - A[i].first <= 2 * K) {
			sum += A[j++].second;
		}
		ans = max(ans, sum);
		sum -= A[i].second;
	}
	cout << ans << "\n";
	return 0;
}
