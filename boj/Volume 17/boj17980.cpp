#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(2 * N);
	for (int i = 0; i < A.size(); ++i) {
		cin >> A[i].first;
		if (A[i].second = i % 2) {
			A[i].first += K;
		}
	}
	sort(A.begin(), A.end());
	int cnt{}, ans{};
	for (auto &p : A) {
		cnt += 1 - 2 * p.second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
	return 0;
}
