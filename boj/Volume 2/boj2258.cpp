#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		int x{}, y{};
		cin >> x >> y;
		A.push_back({y, -x});
	}
	sort(A.begin(), A.end());
	int X{}, ans = -1;
	for (int i = 0; i < N; ++i) {
		M += A[i].second;
		if (i && A[i].first == A[i - 1].first) {
			X += A[i].first;
		} else {
			X = A[i].first;
		}
		if (M <= 0) {
			ans = (ans == -1 ? X : min(ans, X));
		}
	}
	cout << ans << "\n";
	return 0;
}
