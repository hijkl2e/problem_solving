#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{}, L{};
	cin >> M >> N >> L;
	vector<int> A(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<ii> B;
	while (N--) {
		int x{}, y{};
		cin >> x >> y;
		if (y > L) {
			continue;
		}
		B.push_back({x - L + y, x + L - y});
	}
	sort(B.begin(), B.end());
	int ans{};
	for (int i = 0, j = 0; i < M; ++i) {
		while (j < B.size() && B[j].first <= A[i]) {
			if (A[i] <= B[j].second) {
				++ans;
			}
			++j;
		}
	}
	cout << ans << "\n";
	return 0;
}
