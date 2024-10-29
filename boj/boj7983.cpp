#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A;
	for (int i = 0; i < N; ++i) {
		int d{}, t{};
		cin >> d >> t;
		A.push_back({t, d});
	}
	sort(A.rbegin(), A.rend());
	int T = 1e9;
	for (auto &[t, d] : A) {
		T = min(T, t) - d;
	}
	cout << T << "\n";
	return 0;
}
