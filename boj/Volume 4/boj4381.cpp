#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector<ii> B;
	int ans{};
	while (A.size() > 3) {
		int y = A.back(); A.pop_back();
		int x = A.back(); A.pop_back();
		int a = 2 * A[0] + x + y;
		int b = A[0] + 2 * A[1] + y;
		ans += min(a, b);
		if (a < b) {
			B.push_back({A[0], y});
			B.push_back({A[0], -1});
			B.push_back({A[0], x});
			B.push_back({A[0], -1});
		} else {
			B.push_back({A[0], A[1]});
			B.push_back({A[0], -1});
			B.push_back({x, y});
			B.push_back({A[1], -1});
		}
	}
	if (A.size() == 3) {
		ans += A[0] + A[1] + A[2];
		B.push_back({A[0], A[2]});
		B.push_back({A[0], -1});
		B.push_back({A[0], A[1]});
	} else if (A.size() == 2) {
		ans += A[1];
		B.push_back({A[0], A[1]});
	} else {
		ans += A[0];
		B.push_back({A[0], -1});
	}
	cout << ans << "\n";
	for (auto &[u, v] : B) {
		if (v == -1) {
			cout << u << "\n";
		} else {
			cout << u << " " << v << "\n";
		}
	}
	return 0;
}
