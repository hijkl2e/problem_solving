#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int G{}, N{};
	cin >> G >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(), A.end());
	int t{}, cnt{};
	for (auto &p : A) {
		if (t <= p.second) {
			t = p.first;
			++cnt;
		}
	}
	cout << (cnt >= G ? "YES" : "NO") << "\n";
	return 0;
}
