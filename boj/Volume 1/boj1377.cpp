#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	int ans = 1;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, A[i].second - i + 1);
	}
	cout << ans << "\n";
	return 0;
}
