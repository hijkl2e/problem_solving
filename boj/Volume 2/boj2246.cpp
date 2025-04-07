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
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	int minv = 1e9, ans{};
	for (int i = 0; i < N; ++i) {
		if (minv > A[i].second) {
			minv = A[i].second;
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
