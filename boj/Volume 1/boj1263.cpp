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
		cin >> A[i].second >> A[i].first;
	}
	sort(A.rbegin(), A.rend());
	int t = 1e9;
	for (auto &[u, v] : A) {
		t = min(t, u) - v;
	}
	cout << (t < 0 ? -1 : t) << "\n";
	return 0;
}
