#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].second >> A[i].first;
	}
	sort(A.begin(), A.end());
	multiset<int> S;
	while (K--) {
		S.insert(0);
	}
	int ans{};
	for (auto &p : A) {
		auto it = S.lower_bound(p.second);
		if (it != S.begin()) {
			S.erase(--it);
			S.insert(p.first);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
