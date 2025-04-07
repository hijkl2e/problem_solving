#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, L{}, K{};
	cin >> N >> M >> L >> K;
	vector<ii> A(K);
	for (auto &[x, y] : A) {
		cin >> x >> y;
	}
	int ans{};
	for (auto &[x1, y1] : A) {
		vector<int> B;
		for (auto &[x2, y2] : A) {
			if (y1 <= y2 && y2 <= y1 + L) {
				B.push_back(x2);
			}
		}
		sort(B.begin(), B.end());
		for (int i = 0, j = 1; i < B.size(); ++i) {
			while (j < B.size() && B[j] <= B[i] + L) {
				++j;
			}
			ans = max(ans, j - i);
		}
	}
	ans = K - ans;
	cout << ans << "\n";
	return 0;
}
