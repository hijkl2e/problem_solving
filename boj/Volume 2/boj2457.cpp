#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		-1, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
	};
	int N{};
	cin >> N;
	vector<ii> B;
	while (N--) {
		int m1{}, d1{}, m2{}, d2{};
		cin >> m1 >> d1 >> m2 >> d2;
		if (m2 < 3 || m1 > 11) {
			continue;
		}
		int x = A[m1] + d1 - 1;
		int y = A[m2] + d2 - 1;
		B.push_back({x, y});
	}
	sort(B.begin(), B.end());
	int ans{};
	for (int i = 0, j = 59; j < 334;) {
		int p = -1;
		while (i < B.size() && B[i].first <= j) {
			p = max(p, B[i++].second);
		}
		if (p == -1) {
			ans = 0;
			break;
		}
		j = p;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}
