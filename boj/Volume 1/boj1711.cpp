#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> X(N);
	vector<int> Y(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	map<ii, int> A, B;
	int ans{};
	for (int i = 0; i < N; ++i) {
		A.clear();
		B.clear();
		for (int j = 0; j < N; ++j) {
			if (i == j) {
				continue;
			}
			int x = X[j] - X[i];
			int y = Y[j] - Y[i];
			if (x < 0 || (x == 0 && y < 0)) {
				x *= -1;
				y *= -1;
			}
			int g = gcd(x, y);
			x /= g;
			y /= g;
			if (y > 0) {
				++A[{x, y}];
			} else {
				++B[{-y, x}];
			}
		}
		auto it1 = A.begin();
		auto it2 = B.begin();
		while (it1 != A.end() && it2 != B.end()) {
			if (it1->first < it2->first) {
				++it1;
			} else if (it1->first > it2->first) {
				++it2;
			} else {
				ans += it1->second * it2->second;
				++it1, ++it2;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
